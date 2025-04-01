#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
    int fd1=0,fd2=0,ret = 0;
    char buff[1024] = {0};

    printf("argc: %d\n",argc);
    for(int i=0;i<argc;i++){
        printf("argv[%d]: %s\n",i,argv[i]);
    }
    //open src file
    fd1 = open(argv[1],O_RDONLY);
    if(fd1 == -1){
        printf("open src file err\n");
        ret = -1;
        goto err1;
    }
    //open dest file
    fd2 = open("dest.txt",O_WRONLY | O_CREAT,0644);
    if(fd2 == -1){
        printf("open dest file err\n");
        ret = -1;
        goto err2;
    }
    //read src file
    ret = read(fd1,buff,sizeof(buff));
    if(ret == -1){
        printf("read src file err\n");
        goto err2;
    }
    //cpy to dest file
    ret = write(fd2,buff,sizeof(buff));
    if(ret == -1){
        printf("write dest file err\n");
        goto err2;
    }
    err1:
        close(fd1);
    err2:
        close(fd2);
    return 0;
}
