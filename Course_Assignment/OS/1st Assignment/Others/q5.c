#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int pid;
	int a = getpid();
	for (int i = 1; i <= n - 1; i++)
	{
		fork();
		pid = getpid();
		if (a == pid)
			break;
		else
		{
			a = pid;
		}
	}
	printf("[%d %d], ", getpid(), getppid());
	sleep(1);
	return 0;
}
