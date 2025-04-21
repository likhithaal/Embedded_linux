#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>

#define FILETOCHECK     "./test.txt"

int main(){
    int ret = 0;
    ret = chmod(FILETOCHECK,0777);
    if(ret == -1){
        perror("chmod failed");
        return -1;
    }

    return 0;
}