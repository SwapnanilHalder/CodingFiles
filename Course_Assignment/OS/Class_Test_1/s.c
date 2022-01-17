#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// int main() {
//     int y;
//     scanf("%d", &y);

//     printf("0H\n");

//     printf("%dK\n", (y+7));
// }

int main(){
    int y, process_ID;
    scanf("%d",&y);
    process_ID = getpid();
    fork();
    if (process_ID == getpid()) { 
        printf("H\n"); 
        wait(); 
        printf("K\n"); 
        fork();
        if (process_ID != getpid()) {
            sleep(41); 
            printf("D\n");
        }
    }
    else { 
        sleep(y); 
        printf("Q\n"); 
        sleep(7);
    }
    return 0;
}