#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd=0,ret=0;
    fd = open("./hello.txt",O_CREAT|O_WRONLY,0644);
    if(fd == -1){
        printf("open error\n");
        return -1;
    }
    printf("open ok\n");

    ret = write(fd,"hello world",11);
    if(ret == -1){
        printf("write error\n");
        close(fd);
        return -1;
    }
    printf("write %d bytes ok\n",ret);
    close(fd);
    return 0;
}