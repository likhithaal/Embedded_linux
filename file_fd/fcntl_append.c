#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int ret = 0, fd1 = 0;
    fd1 = open("./test.txt",O_RDWR,0644);
    if(fd1 == -1){
        perror("open err\n");
        return -1;
    }
    //i want to append the file which is opened in RDWR mode can be done using ioctl()
    
    //get flag
    ret = fcntl(fd1,F_GETFL); //get file status flag
    if(ret == -1){
        perror("fcntl get err\n");
        close(fd1);
        return -1;
    }
    printf("flags 0x%x\n",ret);

    //set flag
    ret = fcntl(fd1,F_SETFL, ret | O_APPEND); //get file status flag
    if(ret == -1){
        perror("fcntl set err\n");
        close(fd1);
        return -1;
    }

    //get again to recheck
    ret = fcntl(fd1,F_GETFL); //get file status flag
    if(ret == -1){
        perror("fcntl get recheck err\n");
        close(fd1);
        return -1;
    }
    printf("get flags 0x%x\n",ret);
    close(fd1);
    return 0;
}
