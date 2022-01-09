#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int n;
    scanf("%d", &n);
    int process_id;
    int a = getpid();
    for (int i = 0;i<n; i++) {
        fork();
        process_id = getpid();
        if (a == process_id)
            break;
        else
            a = process_id;
    }
    printf("[%d %d]\n", getpid(), getppid());
    sleep(1);
    return 0;
}