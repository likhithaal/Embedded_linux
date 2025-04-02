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

    printf("hello world printf\n");
    write(1,"hello write\n",11);  //same as printf fd = 1 for stdout
    
    fprintf(f,"hiii hello fprintf\n");   //to print on file using file *stream
    fprintf(stdout,"hii hello fprintf stdout\n");  //stdout fd = 1   --- to print on console

    dprintf(1,"hii dprintf\n");  //to print on file using fd

    sprintf(buf,"print buffer\n"); //store in buf
    printf("%s\n",buf); //printf that buf

    snprintf(buf,128,"print size cntl buffer\n");
    printf("%s\n",buf);  //print the buf

    fclose(f);
    return 0;
}