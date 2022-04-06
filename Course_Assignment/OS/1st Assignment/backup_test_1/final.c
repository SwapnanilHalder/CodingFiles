#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 500
#endif /* __STDC_VERSION__ */


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{  int p,x,y;
    for(int x=0; x < 30; x++) {
        for(int y=0; y<30; y++) {
            printf("\n=>%d , %d=<\n", x, y);
                p=fork();
                open("t",O_RDWR|O_CREAT);
                if(p==0)
                {  lseek(3,47,0);lockf(3,F_LOCK,x);
                    sleep(2);printf("K");fflush(stdout);
                    lseek(3,54,0);lockf(3,F_ULOCK,21);
                    sleep(2);printf("J");fflush(stdout);
                }
                else
                {  sleep(1);
                    lseek(3,56,0);
                    lockf(3,F_LOCK,y);
                    printf("Z");fflush(stdout);
                    sleep(4);
                }
        }
    }
}