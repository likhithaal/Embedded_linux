#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int ret = 0, fd1 = 0,fd2 = 0;
    fd1 = open("./test.txt",O_RDWR,0644);
    if(fd1 == -1){
        perror("open err\n");
        return -1;
    }
    
    // fcntl() == file control using fd
    fd2 = fcntl(fd1,F_DUPFD,0); //duplicate fd1 to fd2 same as dup() or dup2()
    // 0 == min fd value or least possible >= 0 (check which min fd available and assign)
    if(fd2 == -1){
        perror("fcntl err\n");
        close(fd1);
        return -1;
    }

    printf("fd1 = %d fd2 = %d\n",fd1,fd2);
    close(fd1);
    close(fd2);
    return 0;
}
