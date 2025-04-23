#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <utime.h>
#include <time.h>
#include <sys/time.h>

#define STRING_FORMAT   0

int main(){

#if STRING_FORMAT
    char time_str[128] = {0};
    time_t t1;
    t1 = time(NULL);     //time() will give the seconds from 1970

    if(t1 == -1){
        perror("time err");
        return -1;
    }

    ctime_r(&t1,time_str);    //converts it to the correct format of time in strings

    printf("Time is %s\n",time_str);

    #else

    struct tm tr;
    time_t t2;
    char time_str[128] = {0};

    t2 = time(NULL);
    if(t2 == -1){
        perror("time err");
        return -1;
    }

    localtime_r(&t2,&tr);  //give you in a structure format

    printf("Time is:\n %d year %d month %d date, %d:%d:%d\n",tr.tm_year + 1900,\
        tr.tm_mon + 1,tr.tm_mday,tr.tm_hour,tr.tm_min,tr.tm_sec);

    strftime(time_str,sizeof(time_str),"%Y-%m-%d %A %H:%M:%S",&tr);  //we can convert to string in our required form
    printf("%s\n",time_str);                                         //%A gives the day name
    #endif

    return 0;
}