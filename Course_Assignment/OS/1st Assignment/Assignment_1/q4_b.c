#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    if (fork() == 0) {
        fork();
        fork();
    }
    wait(0);
    printf("Process\n");
    return 0;
}
