#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid = getpid();
    fork(); fork();
    if (pid != getpid()) {
        fork();
    }

    wait(0);
    printf("Process\n");
    return 0;
}
