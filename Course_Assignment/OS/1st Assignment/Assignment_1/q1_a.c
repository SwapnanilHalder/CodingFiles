#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int a = getpid();
    fork();
    printf("AL");
    sleep(1);
    if (a == getpid())
    {
        printf("BA");
    }
}