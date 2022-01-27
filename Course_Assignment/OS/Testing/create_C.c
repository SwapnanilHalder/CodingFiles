#include <stdio.h>
#include <unistd.h>

int main( )
{ 
    printf("%d\n",getpid( ));
    int p=getpid( );   
    fork( );
    long long int count = 1;
    while (getppid( )==p) {
        count++;
    }
    printf("For process : %d, count is : %lld\n", getpid(), count);
    printf("%d\n",getpid( ));
    printf("%d\n",getppid( ));
    sleep(2);
    // sleep(2);
}