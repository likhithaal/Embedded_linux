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
    int pid = 0;
    if(argc < 2){
        printf("Too few argumnets\n");
        return -1;
    }

    pid = atoi(argv[1]);
    printf("Pid is: %d\n",pid);

    if(kill(pid,SIGINT) == -1){   //kill will send a signal (SIGINT) specified by 2nd arg to the pid
        perror("kill err\n");
        exit(-1);
    }


    /*
    to check kill cmd run any previous code like ./signalexample in background (&)
    check the pid : ps aux | grep signalexample  or
                    ps -ef | grep signalexample
    the run this code with that pid: ./send 38631
    so it will kill the previous process

    */
    return 0;
}