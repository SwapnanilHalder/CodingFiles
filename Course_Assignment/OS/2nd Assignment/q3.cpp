#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
    int p = fork();
    int q = fork();
    cout << p << " ; " << q << endl;
    if (p == 0 && q == 0)
    {
        fork();
    }
    fork();
    printf("%d ", getpid());
}