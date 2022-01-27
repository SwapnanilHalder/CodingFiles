#include <stdio.h>
#include <unistd.h>

int main( )
{ 
    printf("%d ; %d\n",getpid( ),getppid( )); 
    fork( );
    printf("%d , %d\n",getpid( ),getppid( ));
    sleep(2);
}