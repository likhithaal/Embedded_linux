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

    ret = signal(SIGINT,SIG_DFL);    //system will do the default operation corresponding to signal num
    // ret = signal(SIGINT,(sig_t)sig_handler);  //system will do the user defined function
    // ret = signal(SIGINT,SIG_IGN);   //system will ignore that signal
    //Two signals cant be ignored: SIGKILL and SIGSTOP
   
    if(ret == SIG_ERR){
        perror("signal err");
        return -1;
    }

    while(1){
        sleep(1);
    }
    return 0;
}