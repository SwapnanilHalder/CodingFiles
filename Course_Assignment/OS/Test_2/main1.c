#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int g(int num) {
    while(num >= 10) {
        if(fork() == 0)
            return num%10;
        num /= 10;
    }
    return num;
}

int main() {
    int p,u;
    scanf("%d",&u);
    p=g(u);
    printf("%d\n",p);
    sleep(1);
}