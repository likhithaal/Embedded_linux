#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("%d\n",strcmp("ABCD","ABCD"));   //if its equal it gives 0
    printf("%d\n",strcmp("ABCD","a"));   //return -1 bcz ASCII of A < a
    printf("%d\n",strcmp("a","ABCD"));   //return 1 bcz ASCII of a > A

    return 0;
}