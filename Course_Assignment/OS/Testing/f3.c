#include <stdio.h>
#include <unistd.h>


int main() {
    printf("H\n");
    int a = getpid();
    fork();
    int b = getpid();
    printf("%d, %d\n", a, b);
    if(a!=b)
    printf("M\n");
    return 0;
}