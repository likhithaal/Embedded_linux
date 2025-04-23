#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *ptr = NULL;
    char buf[32] = {"helloworld lalr"};
    
    //charecter search

    ptr = strchr(buf,'r');   //strchr gives the first occurance of charecter
    if(ptr != NULL){
        printf("letter %c\n",*ptr);
        printf("index : %ld\n",ptr-buf);
    }

    ptr = strrchr(buf,'r');   //strrchr gives the last occurance of charecter
    if(ptr != NULL){
        printf("letter %c\n",*ptr);
        printf("index : %ld\n",ptr-buf);
    }

    //substring search

    ptr = strstr(buf,"lalr"); 
    if(ptr != NULL){
        printf("string %s\n",ptr);
        printf("index : %ld\n",ptr-buf);
    }

    return 0;
}