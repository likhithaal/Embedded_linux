#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char hostname[256] = {0};
    int ret = 0;

    memset(hostname,0,sizeof(hostname));
    ret = gethostname(hostname,sizeof(hostname));
    if(ret == -1){
        perror("gethostname err");
        return -1;
    }
    puts(hostname);

    return 0;
}