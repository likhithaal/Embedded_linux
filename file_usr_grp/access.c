#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#define FILETOCHECK     "./test.txt"

int main(){
    int ret = 0;
    printf("checking file %s\n",FILETOCHECK);

    ret = access(FILETOCHECK,F_OK);   
    if(ret == -1){
        perror("file doesnot exist");
        return -1;
    }

    ret = access(FILETOCHECK,R_OK);
    if(!ret){
        printf("read Ok\n");
    }else{
        perror("read not allowed");
    }
    
    ret = access(FILETOCHECK,W_OK);
    if(!ret){
        printf("write Ok\n");
    }else{
        perror("write not allowed");
    }

    ret = access(FILETOCHECK,X_OK);
    if(!ret){
        printf("Execute Ok\n");
    }else{
        perror("Execute not allowed");
    }

    return 0;
}