#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char buf[32] = {'L','A','L'};
    puts(buf);

    // memset(buf,0,sizeof(buf));
    bzero(buf,sizeof(buf));     //same as memset but it will make to zero

    puts(buf);
    return 0;
}