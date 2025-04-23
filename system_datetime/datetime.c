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
    time_t t1;
    t1 = time(NULL);

    if(t1 == -1){
        perror("time err");
        return -1;
    }

    printf("Time is %ld\n",t1);

    struct timeval tvalue;
    int ret = 0;
    ret = gettimeofday(&tvalue,NULL);
    
    if(ret == -1){
        perror("gettimeofday err");
        return -1;
    }

    printf("Time %ld seconds + %d us\n",tvalue.tv_sec,tvalue.tv_usec);

    return 0;
}