#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    FILE *f = NULL;
    int ret = 0;
    char buf[128] = {0};

    f = fopen("./test.txt","w+");  //w+ O_RDWR | O_CREATE mode 
    if(f == NULL){
        perror("fopen err");
        return -1;
    }
    ret = fwrite("helloworld",1,10,f);  //1 byte 10ntimes im writing using f pointer
    if(ret > 10){
        perror("fwrite err");
        fclose(f);
        return -1;
    }
    ret = fseek(f,0,SEEK_SET); //same as lseek
    if(ret == -1){
        perror("fseek err");
        fclose(f);
        return -1;
    }
    ret = fread(buf,1,10,f); //10 bytes = 1 * 10
    if(ret < 10){
        if(ferror(f)){    //ferror will give an err in fread or fwrite err
            printf("fread error\n");
            fclose(f);
            return -1;
        }else{
            if(feof(f)){    //check if end of file is reached or not
                printf("reached to end of the file already\n");
                fclose(f);
                return -1;
            }
        }
        clearerr(f);
    }
    printf("fread: %s\n",buf);
    fclose(f);
    return 0;
}
