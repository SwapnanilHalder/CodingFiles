#include <stdio.h>
#include <unistd.h>

int main() {
    if( fork() && fork() ) {
        fork();
    }
    printf("%d -> %d\n", getppid(), getpid());
}