#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>


int main(){

    printf("every user max process: %ld\n",sysconf(_SC_CHILD_MAX));
    printf("system clock tick: %ld\n",sysconf(_SC_CLK_TCK));
    printf("esystem page size: %ld\n",sysconf(_SC_PAGESIZE));

    return 0;
}