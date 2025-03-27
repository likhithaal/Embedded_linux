#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd1=0,fd2=0;
    int ret = 0;
    char buff[20] = {0};
    fd1 = open ("./test.txt",O_RDWR | O_CREAT | O_TRUNC | O_APPEND,0644);
    if(fd1 == -1){
        perror("fd1 open err");
        return -1;
    }
    fd2 = dup(fd1);
    // fd2 = dup2(fd1,1000);   //using dup2 we can get the fd number as we wanted
    printf("fd2 = %d\n",fd2);
    if(fd2 == -1){
        perror("fd2 dup err");
        close(fd1);
        return -1;
    }
    ret = write(fd1,"helloworld",10);
    if(ret == -1){
        perror("write err");
        close(fd1);
        close(fd2);
        return -1;
    }
    lseek(fd2,0,SEEK_SET); //reset the pointer to beginning bcz when we write pointer also moves
                            //so from that place if we read will not get anything
    ret = read(fd2,buff,10); 
    if(ret == -1){
        perror("read err");
        close(fd1);
        close(fd2);
        return -1;
    }
    printf("read bytes : %s\n",buff);
    close(fd1);
    close(fd2);
    return 0;
}