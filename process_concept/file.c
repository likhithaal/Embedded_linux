#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <utime.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>

int main(int argc,char *argv[]){

    int ret = 0,fd = 0;
    fd = open("./test.txt",O_WRONLY|O_TRUNC);
    if(fd == -1){
        printf("open err\n");
        return -1;
    }
    printf("hello\n");

    switch (fork())
    {
        case -1:
            printf("fork err\n");
            close(fd);
            return -1;
        case 0:
            printf("child process\n");
            write(fd,"child says hello",17);
            return 0;
    default:
        printf("parent process\n");
        write(fd,"parent says hello",18);
        return 0;
    }
    return 0;
}