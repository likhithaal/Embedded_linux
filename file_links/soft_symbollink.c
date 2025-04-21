#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#define FILETEST     "./test.txt"

int main(){

    int ret = 0;
    ret = symlink(FILETEST,"softlink_test");   //softlink with file name softlink_test
    if(ret == -1){
        perror("link err");
        return -1;
    }
    /*
    softlink will has the different inode info and same content for both files
    using command we can softlink : ln -s test.txt softlink_test
    we can check using ls -lih test.txt hardlink_test

    both the files pointing to the different inode but has same content in softlink
    */

    return 0;
}