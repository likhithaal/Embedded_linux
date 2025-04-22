#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(){

    /* OUTPUTS */
    puts("hiii");    //added \n automatically
    printf("hello");  //not added \n --- manually we need to add \n 
    putchar('A');
    putchar('B');    // not added \n 

    fputc('P',stdout);   //stdout fd = 1   not added \n
    fputc('Q',stdout); 
    fputs("hii how are you",stdout);
    fputs("\n",stdout);

     /* INPUTS */
    char buf[128] = {0};
    scanf("%s",buf);   //take only till space
    gets(buf);  //include spaces 
    puts(buf);

    int ch;
    ch = getchar();
    printf("ch : %c",ch);

    char str[128] = {0};
    fgets(str,sizeof(str),stdin);
    printf("%s",str);
    return 0;
}
