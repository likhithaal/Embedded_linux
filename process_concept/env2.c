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

extern char **environ;

int main(int argc,char *argv[]){

    int ret = 0;

    if(argc < 2){
        printf("too few arguments\n");
        return -1;
    }

    // ret = putenv(argv[1]);    // ./env TODAY=MONDAY  -> if its present it will overwrite otherwise it will create

    ret = setenv(argv[1],"TUESDAY",0);  // ./env TODAY    last parameter is overwrite

    if(ret){
        printf("setenv err\n");
        return -1;
    }

    for(int i=0;environ[i] != NULL;i++){
        printf("%s\n",environ[i]);
    }

    //unset env
    ret = unsetenv(argv[1]);
    for(int i=0;environ[i] != NULL;i++){
        printf("%s\n",environ[i]);
    }

    //clearenv() will clear the whole env variable

    return 0;
}