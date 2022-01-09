#include <stdio.h>

int main()
{
	int q = getpid();
	fork();
	fork();
	int p = getpid();
	fork();
	if (p == getpid() && q != getpid())
	{
		fork();
	}
	printf("P\n");
	sleep(1);
	return 0;
}
