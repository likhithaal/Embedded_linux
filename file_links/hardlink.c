#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#define FILETEST     "./test.txt"

int main(){

    int ret = 0;
    ret = link(FILETEST,"hardlink_test");   //hardlink with file name hardlink_test
    if(ret == -1){
        perror("link err");
        return -1;
    }
    /*
    hardlink will has the same inode info and same content for both files
    using command we can hardlink  ln test.txt hardlink_test
    we can check using ls -lih test.txt hardlink_test

    both the files pointing to the same inode in hardlink
    */

    return 0;
}