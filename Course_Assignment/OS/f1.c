#include <stdio.h>
#include <unistd.h>




int main() {
    // printf("A %d => %d\n", getpid(), getppid());
    // fork();
    // printf("B %d => %d\n", getpid(), getppid());
    // sleep(1);
    // printf("C %d => %d\n", getpid(), getppid());
    int a=5;
    fork();
    printf("A %d\n", a);
    a++;
    printf("B %d\n", a);
    return 0;
return 0;
}