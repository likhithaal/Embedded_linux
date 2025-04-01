#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int ret = 0, fd = 0;
    fd = open("./test.txt",O_RDWR,0644);
    if(fd == -1){
        perror("open err\n");
        return -1;
    }
    // ret = truncate("./test.txt",4);  //open the file that already created and truncate/reduce to 4 bytes
    //check ls -l test.tyxt -- reduce to 4 bytes

    ret = ftruncate(fd,1024); //1k -- open the file using fd then extend file size by adding 00000
    if(ret == -1){
        perror("truncate err\n");
        return -1;
    }
    return 0;
}