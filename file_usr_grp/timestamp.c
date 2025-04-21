#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <utime.h>

#define FILETOCHECK     "./test.txt"

int main(){
    int ret = 0;

    struct utimbuf times;
    time_t cur_sec;
    time(&cur_sec);
    times.actime = cur_sec;
    times.modtime = cur_sec;

    // ret = utime(FILETOCHECK,NULL);  
    ret = utime(FILETOCHECK,&times);  
    
    if(ret == -1){
        perror("utime failed");
        return -1;
    }

    return 0;
}