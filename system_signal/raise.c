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

static void sig_handler(int sig){
    printf("Received signal number is : %d\n",sig);
}

int main(){
    sig_t ret = NULL;

    ret = signal(SIGINT,(sig_t)sig_handler);
   
    if(ret == SIG_ERR){
        perror("signal err");
        return -1;
    }

    while(1){
        if(raise(SIGINT) != 0){         //every 2 sec it will automatically raise the signal SIGINT
            printf("raise err\n");
            return -1;
        }
        sleep(2);
    }
    return 0;
}