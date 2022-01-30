
// que1

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd, itr;
    char w[100];
    cin >> w; // enter the filename
    fd = open(w, O_RDONLY);
    char c;
    read(fd, &c, 1);
    printf("%c", c);
    int i = 1;
    while (c != 'a')
    {
        i++;
        read(fd, &c, 1);
        //printf("%c", c);
    }
    printf("%d\n", i);
}

// que2

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd, itr;
    char w[100];
    cin >> w; // enter the filename
    fd = open(w, O_RDONLY);
    char c;
    int i = 0;
    while (read(fd, &c, 1))
    {
        i++;
    }
    printf("%d\n", i);
}

// que3

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd, itr;
    char w[100];
    cin >> w; // enter the filename
    fd = open(w, O_RDONLY);
    char c;
    int i = 0;
    while (read(fd, &c, 1))
    {
        printf("%c", c);
    }
    printf("\n");
}

//que4

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd;
    char w[100], c;
    cin >> w; // enter the filename
    fd = open(w, O_RDWR);
    int i = 0;
    while (read(fd, &c, 1))
    {
        printf("%c", c);
        if(c=='a')
        {
            lseek(fd, -1, SEEK_CUR);
            write(fd, "K", 1);
        }
    }
    printf("\n");
}

// que5

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd,fd1;
    char file1[100], file2[100], c;
    cin >> file1;
    cin >> file2;
    fd = open(file1, O_RDONLY); // enter first file name
    fd1 = open(file2, O_WRONLY); // enter second file name
    char c;
    int i = 0;
    while (read(fd, &c, 1))
    {
        printf("%c", c);
        write(fd1, &c, 1);
    }
    printf("\n");
}


// que6.cpp

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd,fd1;
    char file1[100], file2[100], c;
    cin >> file1;
    cin >> file2;
    fd = open(file1, O_RDWR);// enter first file name
    lseek(fd, 0, SEEK_END);// enter second file name
    fd1 = open(file2, O_RDONLY);
    while (read(fd1, &c, 1))
    {
        write(fd, &c, 1);
    }
}

// que7

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd, k;
    char w[100], c;
    cin >> w;        // enter file name
    fd = open(w, O_RDONLY);
    int i = lseek(fd, 0, SEEK_END);
    int j = 1;
    while (i > 0)
    {
        lseek(fd, -j, SEEK_END);
        read(fd, &c, 1);
        printf("%c", c);
        j++;
        i--;
    }
    printf("\n");
}

// que8

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd, k;
    char w[100], c;
    cin >> w; // enter the file name
    cin >> k; // enter the number
    fd = open(w, O_RDWR);
    lseek(fd, -k, SEEK_END);
    read(fd, &c, 1);
    char temp1 = c;
    lseek(fd, k - 1, SEEK_SET);
    read(fd, &c, 1);
    char temp2 = c;
    lseek(fd, k - 1, SEEK_SET);
    write(fd, &temp1, 1);
    lseek(fd, -k, SEEK_END);
    write(fd, &temp2, 1);
}

//que9

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd, fd1;
    char first[100],second[100],c;
    cin >> first; // enter file1
    cin >> second;// enter file2
    fd = open(first, O_RDONLY);
    fd1 = open(second, O_WRONLY);
    int i = lseek(fd, 0, SEEK_END);
    int j = 1;
    while (i > 0)
    {
        lseek(fd, -j, SEEK_END);
        read(fd, &c, 1);
        write(fd1, &c, 1);
        j++;
        i--;
    }
    printf("\n");
}

// que10

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd;
    char w[100], c;
    string s;
    cin >> w;// enter file name
    cin >> s;// enter string
    fd = open(w, O_RDWR);
    lseek(fd, 0, SEEK_END);
    int i = 0;
    while (i < s.length())
    {
        char temp = s[i];
        write(fd, &temp, 1);
        i++;
    }
}

// que11


#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd;
    char w[100], c;
    cin >> w;// enter filename
    string s;
    fd = open(w, O_RDWR);
    int len = lseek(fd, 0, SEEK_END);
    int i = len;
    lseek(fd, 0, SEEK_SET);
    while (i > 0)
    {
        read(fd, &c, 1);
        s += c;
        i--;
    }
    lseek(fd, 0, SEEK_SET);
    write(fd, "x", 1);
    i = 0;
    while (i < len)
    {
        char temp = s[i];
        write(fd, &temp, 1);
        i++;
    }
}


//que12

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd, fd1;
    char first[100], second[100], c;
    cin >> first; // enter file name
    fd = open(first, O_RDWR);
    lseek(fd, 0, SEEK_SET);
    int j = 0;
    while (read(fd, &c, 1))
    {
        second[j] = c;
        j++;
        second[j] = 'x';
        j++;
    }
    lseek(fd, 0, SEEK_SET);
    int i = 0;
    while (i < j - 1)
    {
        char temp = second[i];
      //  printf("%c", temp);
        write(fd, &temp, 1);
        i++;
    }
    printf("\n");
}

// que13

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int fd;
    char w[100], c;
    cin >> w; // enter file name
    fd = open(w, O_RDONLY);
    lseek(fd, -1, SEEK_END);
    int num = 0, place = 1;
    while (read(fd, &c, 1))
    {
        if (c == ' ')
        {
            break;
        }
        else
        {
            num += (c - '0') * place;
            place *= 10;
            lseek(fd, -2, SEEK_CUR);
        }
    }
    printf("%d", num);
    printf("\n");
}


