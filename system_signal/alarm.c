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
    printf("Alarm Time out\n");
    exit(1);  //after alarm timeout it will exit
    // alarm(3);  // itb will keep continuing
}

int main(int argc,char *argv[]){
    sig_t ret = NULL;
    int sec = 0;

    if(argc < 2){
        printf("Too few arguments\n");
        return -1;
    }

    ret = signal(SIGALRM,(sig_t)sig_handler);
   
    if(ret == SIG_ERR){
        perror("signal err");
        return -1;
    }

    sec = atoi(argv[1]);
    printf("Setup %d second\n",sec);
    
    // start the alarm
    alarm(sec);

    while(1){
        sleep(1);
    }
    return 0;
}