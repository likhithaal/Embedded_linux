#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = 0;
    fd = open("./test.txt",O_WRONLY | O_TRUNC,0644);
    //O_TRUNC flag wil reduce the file size to 0 if it ocuupied some size (it will erase everything)
    
    //O_APPEND flag will start writing from the end of the flag it will not erase the previous data
    if(fd == -1){
        perror("open err");
        return -1;
    }
    close(fd);
    return 0;
}