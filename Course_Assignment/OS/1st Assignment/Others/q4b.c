#include <stdio.h>

int main()
{
    if (fork() == 0)
    {
        fork();
        fork();
    }
    wait(0);
    printf("P\n");
    return 0;
}
