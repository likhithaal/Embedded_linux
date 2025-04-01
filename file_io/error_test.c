#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
/*
error type:
errno (it will give the error number)
strerror() (it will give the exact meaning of errno)
perror() (directly it will give what exactly the error is)
*/
int main(){
    int fd=0;
    printf("initial errno: %d\n",errno);

    fd = open("haha.txt",O_RDONLY);
    if(fd == -1){
        printf("errno : %d\n",errno);
        printf("errorno string is %s\n",strerror(errno));
        perror("error is: ");     
        return -1;
    }
    return 0;
}
