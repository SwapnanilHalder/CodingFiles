#include <stdio.h>

int main()
{
    int p = getpid();
    fork();
    printf("AL");
    sleep(1);
    if (p == getpid())
    {
        printf("BA");
    }
}
