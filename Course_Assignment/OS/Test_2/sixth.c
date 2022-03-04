#include<stdio.h>
#include<pthread.h>
int u,k=0;
void *d() {
    scanf("%d",&u);
    u <<=1 ; 
    k=1;
}
main()
{
    pthread_t a;
    pthread_create(&a,NULL,&d,NULL);
    sleep(5);
    if (k) printf("%d\n",u); else printf("68");
}