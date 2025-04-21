#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    printf("hiiiii\n");
    printf("hello");

    //when we give sleep inside while(1) , print statement upto \n only will print, 
    //if we are giving print after \n without \n will not print anything
    //for that we can use either fflush or fclose

    fflush(stdout);

    // fclose(stdout);

    while(1){
        sleep(1);
    }

    return 0;
}