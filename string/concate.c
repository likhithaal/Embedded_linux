#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *str = "hello";
    char buf[32] = {'L','A','L',' '};
    strcat(buf,str);
    puts(buf);
    return 0;
}