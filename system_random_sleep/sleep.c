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

    struct timespec req;   //this struct used to sleep in nanosec
    req.tv_sec = 2;
    req.tv_nsec = 0;
   
    puts("Sleep start\n");

    // sleep(2);  //sleep 2 sec
    //usleep()  //micro sec
    nanosleep(&req,NULL);
    
    puts("Sleep ends\n");
    return 0;
}