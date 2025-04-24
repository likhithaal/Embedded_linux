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
    char *base = NULL;
    base = malloc(100);  //100 bytes
    if(base == NULL){
        perror("malloc err");
        return -1;
    }
    memset(base,1,100);
    *(base + 0) = 20;
    *(base + 1) = 25;
    free(base);
    base = NULL;   //after freeing good to reinitialise to NULL
    return 0;
}