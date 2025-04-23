#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //convert string to number

    printf("atoi %d\n",atoi("500"));       //int
    printf("atol : %ld\n",atol("500"));    //long int
    printf("atoll : %lld\n",atoll("500"));  //long long int

    return 0;
}