#include <stdio.h>
#include <unistd.h>

int main() {
    int a, b;
    a=getpid();
    fork();
    b = getpid();
    if (a == b) {
        sleep(1);
    }
    else {
        printf("L%d %d\n", getpid(), getppid());
        sleep(2);
        printf("T%d %d\n", getpid(), getppid());
    }
}