#include<stdio.h>
#include<signal.h>
int count=0;
void a();
void b(){
	count++;
	signal(SIGINT, a);
}
void a(){ 
	count++;
	if(count==5)
	signal(SIGINT, SIG_DFL);
	else
	signal(SIGINT,b);
 }
main()
{  
	signal(SIGINT, a);
	for(;;);
}