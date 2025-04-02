#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    FILE *f = NULL;
    int ret = 0;
    char buf[128] = {0};

    f = fopen("./test.txt","w+");  //w+ O_RDWR | O_CREATE mode 
    if(f == NULL){
        perror("fopen err");
        return -1;
    }

    fprintf(f,"hiii hello %d\n",100);   //to print on file f

    fprintf(stdout,"hii hello %d\n",100);  //stdout fd = 1   --- to print on console

    fclose(f);
    return 0;
}