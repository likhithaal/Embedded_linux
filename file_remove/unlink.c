#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int ret = 0;

    // unlink() can remove only files
    ret = unlink("test.txt");
    if(ret == -1){
        perror("unlink error");
        return -1;
    }

    /*
    to check unlink first link some 2 files to test.txt
    then unlink the base file test.txt 
    still the contents of other files which are linked to the base file will be there
    ln test.txt test1.txt 
    ln test.txt test2.txt 
    */
    return 0;
}