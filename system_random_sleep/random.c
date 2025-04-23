#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <utime.h>
#include <time.h>
#include <sys/time.h>

int main(){
    int ret = 0;

    /*
    if we are not using srand , rand will give thee same number always
    so by using srand of time it will change /reset on time 
    srand is the seed for rand
    */

    srand(time(NULL));  

    for(int i=0;i<5;i++){
        ret = rand() % 100; //%100 is just to reduce the number size bcz its a big number
        printf("%d ",ret);
    }
    printf("\n");
    return 0;
}