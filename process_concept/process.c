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

    int ret = 0;
    // printf("pid:%d parent pid:%d\n",getpid(),getppid());
    // fork returns 2 times one for parent and other for child
    // child is the copy of parent
    ret = fork();
    if(ret == -1){
        printf("fork err\n");
        return -1;
    }
    else if(ret == 0){
        //child process
        printf("child pid:%d parent pid:%d\n",getpid(),getppid());
    }
    else{
        //parent process
        printf("parent pid:%d parent parent pid:%d child pid:%d\n",getpid(),getppid(),ret);
    }
    // printf("fork val: %d\n",ret);
    // printf("hii\n");
    return 0;
}