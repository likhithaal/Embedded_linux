#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SELECT_FD 0

int main(){
    //we can convert fd to file * and viceversa

    int fd = 0;
    int ret = 0;
    FILE *file = NULL;

    #if SELECT_FD

    fd = open("./test.txt",O_CREAT | O_WRONLY | O_TRUNC ,0666);

    if(fd == -1){
        perror("open fails\n");
        return -1;
    }

    file = fdopen(fd,"w");   //convert fd to FILE*
    // mode has to match with the flags in open()
    if(file == NULL){
        perror("fdopen fails");
        close(fd);
        return -1;
    }

    ret = fwrite("helloworld",1,10,file);
    if(ret < 10){
        printf("write file err or EOF\n");
        fclose(file);
        return -1;
    }
    fclose(file);

    #else

    file = fopen("./test.txt","w");
    if(file == NULL){
        perror("file open fails\n");
        return -1;
    }

    fd = fileno(file); //convert FILE* to fd
    if(fd == -1){
        perror("fd error\n");
        fclose(file);
        return -1;
    }
    ret = write(fd,"hiii_hello",10);

    if(ret < 10){
        printf("write fails\n");
        return -1;
    }

    close(fd);

    #endif

    return 0;
}