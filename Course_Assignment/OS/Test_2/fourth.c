#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// create a file named file_name

int main(){
    int file = open("file_name", O_RDWR);
    int i=0;
    if (fork()){
        while (!i) i=lseek(file,0,SEEK_END);
        printf("M\n");
    }
    else {
        printf("U\n");
        write(file, "U", 1);
    }
}