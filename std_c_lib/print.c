#include <stdio.h>
#include <unistd.h>

int main(){

    printf("hello world\n");

    write(1,"hello world",11);  //same as printf fd = 1 for stdout

    return 0;
}