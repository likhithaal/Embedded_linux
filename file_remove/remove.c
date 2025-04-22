#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int ret = 0;

    // remove() can remove both files and directory
    ret = remove("test.txt");
    if(ret == -1){
        perror("remove error");
        return -1;
    }

    /*
    but remove() can delete the dir only if its a empty dir
    ret = remove("test_dir");
    */
    return 0;
}