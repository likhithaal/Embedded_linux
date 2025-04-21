#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int ret = 0;
    char buff[128] = {0};
    ret = readlink("softlink_test",buff,128);   //softlink with file name softlink_test
    if(ret == -1){
        perror("read link err");
        return -1;
    }
    printf("read link %d\n",ret);
    printf("PATH in the link file %s\n",buff);
    
    return 0;
}