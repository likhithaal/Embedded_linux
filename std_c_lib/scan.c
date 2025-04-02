#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    char buf[128] = {0};

    //input asked for 1st time
    scanf("%s",buf);   //accepts till space
    printf("%s\n",buf); 

    //input asked for 2nd time
    fscanf(stdin,"%s",buf);
    printf("%s\n",buf);

    //input asked for 3rd time
    int data = 0;
    char buf1[128] = {0};
    char buf2[128] = {0};
    sscanf("20 sscanf hii","%d %s %s",&data,buf1,buf2);
    printf("data: %d buff1: %s buff2: %s",data,buf1,buf2);

    return 0;
}