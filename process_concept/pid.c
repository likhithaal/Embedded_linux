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
    printf("Pid is %d\n",getpid());
    return 0;
}