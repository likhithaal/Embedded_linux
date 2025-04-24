#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <utime.h>
#include <time.h>
#include <sys/time.h>

int main(){

    while(1);

    /*
    kill -l is the command that shows all signals to kill
    to stop the program:
    ctrl + c : SIGINT -> 2nd signal
    check the pid of the process kill -2 pid

    ctrl + \ : SIGQUIT -> 3rd signal
    */
    return 0;
}