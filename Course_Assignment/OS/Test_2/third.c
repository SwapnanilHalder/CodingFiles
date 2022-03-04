#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void main() {
    (fork()&&fork())||fork();
    printf("pid = %d ; ppid = %d\n", getpid(), getppid());
    sleep(1);
}