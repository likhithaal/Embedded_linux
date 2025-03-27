#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main(){
    int fd=0;
    printf("initial errno: %d\n",errno);

    fd = open("haha.txt",O_RDONLY);
    if(fd == -1){
        printf("errno : %d\n",errno);
        return -1;
    }
    return 0;
}
