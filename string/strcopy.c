#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char buf[32] = {0};
    strcpy(buf,"hii hello");
    puts(buf);
    return 0;
}