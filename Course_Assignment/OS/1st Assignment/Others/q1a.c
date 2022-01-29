#include <stdio.h>
#include <unistd.h>

int main()
{
    int p = getpid();
    fork();
    if(p == getppid()) {
        sleep(1);
    }
    printf("AL");
    if (p == getpid())
    {
        printf("BA");
    }
}
