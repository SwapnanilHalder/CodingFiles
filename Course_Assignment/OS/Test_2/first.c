#include <stdio.h>

int n=0;
int solve() {  
    int p,q;
    p=getpid();
    fork(); fork(); fork(); fork();
    if(p==getpid()){
        fork(); fork(); fork(); fork(); fork(); fork(); fork();
    }
    printf("T");fflush(stdout);
    sleep(1);
}

int main() {
    solve();
    sleep(10);
    printf("n = %d\n", n);
}