#include <stdio.h>

int main()
{
    int p = getpid();
    fork();
    fork();
    if (p != getpid())
    {
        fork();
    }

    wait(0);
    printf("P\n");
    return 0;
}
