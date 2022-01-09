#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int a = getpid();
    fork();
    printf("AL");
    if (a == getpid())
    {
        sleep(1);
        printf("BA\n");
    }
}