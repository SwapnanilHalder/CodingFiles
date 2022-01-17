#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void n_process(int n) {
    printf("Entered %d\n", n);
    if(n ==  0) {
        return;
    }
    else {
        n_process(n-1);
    }
}

int main() {
    int n,p;
    scanf("%d", &n);
    int id;
    int process_id = getpid();
    int count=1;
    while ( count < n )
    {
        fork();
        id = getpid();
        if (process_id == id)
            break;
        else
            process_id = id;
        count++;
    }
    printf("A\n");
}

// #include <stdio.h>
// int main( )
// {   int n,p;
//     scanf("%d",&n);
//     few missing lines
//     printf("A\n");
// }