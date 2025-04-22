#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int ret = 0;

    // rename() can rename the file under the same directory 
    ret = rename("test_old","test_new");
  
    // rename() can rename the file under the different location 
    // ret = rename("test_old","../../test_new");

    if(ret == -1){
        perror("rename error");
        return -1;
    }
    return 0;
}