#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd,i=0,k; char c;
	fd=open("abcd", O_RDONLY);
	while(1)
	{
		lseek(fd,i,SEEK_SET);
		k = read(fd,&c,1);
		if(k==0)
			break;
		printf("%c", c);
		i++;
	}
}