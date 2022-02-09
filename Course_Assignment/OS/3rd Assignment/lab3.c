
// que1


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store, itr;
    char w[100];
    
    file_store = open(w, O_RDONLY);
    char c;
    read(file_store, &c, 1);
    printf("%c", c);
    int i = 1;
    while (c != 'a')
    {
        i++;
        read(file_store, &c, 1);
        //printf("%c", c);
    }
    printf("%d\n", i);
}

// que2


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store, itr;
    char w[100];
    file_store = open(w, O_RDONLY);
    char c;
    int i = 0;
    while (read(file_store, &c, 1))
    {
        i++;
    }
    printf("%d\n", i);
}

// que3


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store, itr;
    char w[100];
    
    file_store = open(w, O_RDONLY);
    char c;
    int i = 0;
    while (read(file_store, &c, 1))
    {
        printf("%c", c);
    }
    printf("\n");
}

//que4


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store;
    char w[100], c;
    
    file_store = open(w, O_RDWR);
    int i = 0;
    while (read(file_store, &c, 1))
    {
        printf("%c", c);
        if(c=='a')
        {
            lseek(file_store, -1, SEEK_CUR);
            write(file_store, "K", 1);
        }
    }
    printf("\n");
}

// que5


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store,fd1;
    char file1[100], file2[100], c;
    
    file_store = open(file1, O_RDONLY); // enter first file name
    fd1 = open(file2, O_WRONLY); // enter second file name
    char c;
    int i = 0;
    while (read(file_store, &c, 1))
    {
        printf("%c", c);
        write(fd1, &c, 1);
    }
    printf("\n");
}


// que6.cpp


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store,fd1;
    char file1[100], file2[100], c;
    
    file_store = open(file1, O_RDWR);// enter first file name
    lseek(file_store, 0, SEEK_END);// enter second file name
    fd1 = open(file2, O_RDONLY);
    while (read(fd1, &c, 1))
    {
        write(file_store, &c, 1);
    }
}

// que7


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store, k;
    char w[100], c;
    file_store = open(w, O_RDONLY);
    int i = lseek(file_store, 0, SEEK_END);
    int j = 1;
    while (i > 0)
    {
        lseek(file_store, -j, SEEK_END);
        read(file_store, &c, 1);
        printf("%c", c);
        j++;
        i--;
    }
    printf("\n");
}

// que8


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store, k;
    char w[100], c;
    file_store = open(w, O_RDWR);
    lseek(file_store, -k, SEEK_END);
    read(file_store, &c, 1);
    char temp1 = c;
    lseek(file_store, k - 1, SEEK_SET);
    read(file_store, &c, 1);
    char temp2 = c;
    lseek(file_store, k - 1, SEEK_SET);
    write(file_store, &temp1, 1);
    lseek(file_store, -k, SEEK_END);
    write(file_store, &temp2, 1);
}

//que9


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store, fd1;
    char first[100],second[100],c;
    file_store = open(first, O_RDONLY);
    fd1 = open(second, O_WRONLY);
    int i = lseek(file_store, 0, SEEK_END);
    int j = 1;
    while (i > 0)
    {
        lseek(file_store, -j, SEEK_END);
        read(file_store, &c, 1);
        write(fd1, &c, 1);
        j++;
        i--;
    }
    printf("\n");
}

// que10


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store;
    char w[100], c;
    file_store = open(w, O_RDWR);
    lseek(file_store, 0, SEEK_END);
    int i = 0;
    while (i < s.length())
    {
        char temp = s[i];
        write(file_store, &temp, 1);
        i++;
    }
}

// que11



#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store;
    char w[100], c;
    file_store = open(w, O_RDWR);
    int len = lseek(file_store, 0, SEEK_END);
    int i = len;
    lseek(file_store, 0, SEEK_SET);
    while (i > 0)
    {
        read(file_store, &c, 1);
        s += c;
        i--;
    }
    lseek(file_store, 0, SEEK_SET);
    write(file_store, "x", 1);
    i = 0;
    while (i < len)
    {
        char temp = s[i];
        write(file_store, &temp, 1);
        i++;
    }
}


//que12


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store, fd1;
    char first[100], second[100], c;
    file_store = open(first, O_RDWR);
    lseek(file_store, 0, SEEK_SET);
    int j = 0;
    while (read(file_store, &c, 1))
    {
        second[j] = c;
        j++;
        second[j] = 'x';
        j++;
    }
    lseek(file_store, 0, SEEK_SET);
    int i = 0;
    while (i < j - 1)
    {
        char temp = second[i];
      //  printf("%c", temp);
        write(file_store, &temp, 1);
        i++;
    }
    printf("\n");
}

// que13


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int file_store;
    char w[100], c;
    file_store = open(w, O_RDONLY);
    lseek(file_store, -1, SEEK_END);
    int num = 0, place = 1;
    while (read(file_store, &c, 1))
    {
        if (c == ' ')
        {
            break;
        }
        else
        {
            num += (c - '0') * place;
            place *= 10;
            lseek(file_store, -2, SEEK_CUR);
        }
    }
    printf("%d", num);
    printf("\n");
}


