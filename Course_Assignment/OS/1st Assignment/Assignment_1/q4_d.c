#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int q = getpid();
	fork(); fork();
	int p = getpid();
	fork();
	if (p == getpid() && q != getpid()) {
		fork();
	}
	printf("process\n");
	sleep(1);
	return 0;
}
