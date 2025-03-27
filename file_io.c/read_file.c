#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd=0,ret=0;
    char buff[32] = {0};
    fd = open("./hello.txt",O_RDONLY,0644);
    if(fd == -1){
        printf("open error\n");
        return -1;
    }
    printf("open ok\n");

    ret = read(fd,buff,11);
    if(ret == -1){
        printf("read error\n");
        close(fd);
        return -1;
    }
    printf("read %d bytes --> %s\n",ret,buff);
    close(fd);
    return 0;
}
