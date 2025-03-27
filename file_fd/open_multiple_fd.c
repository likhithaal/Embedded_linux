#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd1=0,fd2=0;
    fd1 = open ("./test.txt",O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,0644);
    if(fd1 == -1){
        perror("fd1 open err");
        return -1;
    }
    fd2 = open ("./test.txt",O_WRONLY | O_APPEND,0644);
    if(fd2 == -1){
        perror("fd2 open err");
        close(fd1);
        return -1;
    }
    //using echo command we can write something to the file in terminal 
    write(fd1,"hello",5);
    write(fd2,"heyyyyyy",8);
    close(fd1);
    close(fd2);
    return 0;
}