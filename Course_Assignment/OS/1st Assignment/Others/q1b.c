#include <stdio.h>
#include <unistd.h>

int main()
{
	int p = getpid();
	fork();
	printf("AL");
	if (p == getpid())
	{
		sleep(1);
		printf("BA\n");
	}
}
