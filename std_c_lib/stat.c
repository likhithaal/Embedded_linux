#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(){
    struct stat st;
    //status of the file

    int ret = 0;

    ret = stat("./test.txt",&st);
    // ret = lstat("./linkerfile",&st);

    /*
    like that we can get the status using fd 
    fstat(fd,&st);
    we can use stat(), fstat(), lstat()
    lstat() will act same as stat() 
    but if there is any linker file it will give status of that linker file as well

    we can create a soft link for the test.txt and check
    ln -s test.txt linkerfile
    */

    if(ret == -1){
        perror("stat err\n");
        return -1;
    }

    printf("File type:                ");

    switch (st.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ld\n", (long) st.st_ino);
    printf("Mode:                     %lo (octal)\n",(unsigned long) st.st_mode);
    printf("Link count:               %ld\n", (long) st.st_nlink);
    printf("Ownership:                UID=%ld  GID=%ld\n",(long) st.st_uid, (long) st.st_gid);
    printf("Preferred I/O block size: %ld bytes\n",(long) st.st_blksize);
    printf("File size:                %lld bytes\n",(long long) st.st_size);
    printf("Blocks allocated:         %lld\n",(long long) st.st_blocks);
    printf("Last status change:       %s", ctime(&st.st_ctime));
    printf("Last file access:         %s", ctime(&st.st_atime));
    printf("Last file modification:   %s", ctime(&st.st_mtime));

    exit(EXIT_SUCCESS);

    return 0;
}
