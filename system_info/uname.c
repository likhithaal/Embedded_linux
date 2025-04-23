#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

int main(){
    int ret = 0;
    struct utsname info = {0};
    ret = uname(&info);
    if(ret == -1){
        perror("uname err");
        return -1;
    }

    printf("OS name: %s\n",info.sysname);
    printf("Host name: %s\n",info.nodename);
    printf("Kernel version: %s\n",info.release);
    printf("Distribution version: %s\n",info.version);
    printf("Hardware version: %s\n",info.machine);

    return 0;
}