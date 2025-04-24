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

// extern char **environ;

int main(int argc,char *argv[]){

    // for(int i=0;environ[i] != NULL;i++){
    //     printf("%s\n",environ[i]);     //in terminal we can just give env
    // }

    //another way to get env variables

    const char *env = NULL;
    if(argc < 2){
        printf("too few arguments\n");
        return -1;
    }

    env = getenv(argv[1]);
    if(env == NULL){
        printf("getenv err\n");
        return -1;
    }
    printf("%s\n",env);

    //give interminal like ./env PATH
    //same as in terminal echo $PATH
    return 0;
}