#include <stdio.h>
#include <fcntl.h>

int main(){
    int file_desp  =  open("tmp", O_RDWR);
    int i = 0;
    if (fork()) {
        while (!i) i=lseek(file_desp,0,SEEK_END);
        printf("M\n");
    }
    else {
        printf("U\n");
        write(file_desp, "U", 1);
    }
}