#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
    read() , write()
-----------------------------
   buffer cache ( KERNEL)
-----------------------------
    hard drive
*/


int main(){
    int fd = 0;
    int ret = 0;
    char buf[4096] = {0};

    fd = open("./test.txt",O_RDWR,0644);  //w+ O_RDWR | O_CREATE mode 
    if(fd == -1){
        perror("open err");
        return -1;
    }
    for(int i=0;i<4096;i++){
        write(fd,buf,sizeof(buf)); //write 4096 times of 4k buffer
    }
    // at this point the user data actually copied to kernel buffer cache area 
    fsync(fd);       //same as flag O_SYNC
    // this function will force the kernel to write the cached data buffer
    // from user to hard drive

    fdatasync(fd);  //sync up data, not manage info of the file
    //same as fdatasync we can use the flag O_DSYNC
    sync();    //it will sync all files in kernel cache buff area
    close(fd);

    // we can check the file size
    // ls -lh test.txt (-h for human readable)
    // we will get 16M --> 4096 times 4k
    return 0;
}