#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
//hole file means we had skipped a small part of file (empty part)
int main(){
    int fd = 0,ret = 0;
    unsigned char buff[1024] = {0};
    fd = open("test.txt",O_WRONLY|O_CREAT,0644);  //if a file is already created it will be overwritten
    if(fd < 0){
        perror("open err ");
        return -1;
    }
    //skip 1024 bytes of the file
    ret = lseek(fd,1024,SEEK_SET); //SEEK_SET move from initial position to 1024 bytes
    if(ret == -1){
        perror("lseek err ");
        close(fd);
        return -1;
    }
    //write 1024 bytes of the file
    ret = write(fd,buff,1024);
    if(ret == -1){
        perror("write error ");
        close(fd);
        return -1;
    }
    printf("written %d bytes into file\n",ret);
    close(fd);

    //we skipped 1k and wrote 1k data so totak file size musrt be 2k
    //we can check the file size using ls -l test.txt

    /*
    memory management:
    1 block(4k) = 8 sectors
    1 sector = 512 bytes
    so we can check how many blocks our code has taken ? 
    check using : du -h test.txt = 4k (so it took 1 block)
    */
    return 0;
}