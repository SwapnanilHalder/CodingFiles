/*

Name : Swapnanil Halder
Roll No. : 18MA20046
Programs : C++ programs

*/
// que1

#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int file_store, itr;
    char file_name[100];
    cin >> file_name; // enter the filename
    file_store = open(file_name, O_RDONLY);
    char character;
    read(file_store, &character, 1);
    printf("%c", character);
    int i = 1;
    while (character != 'a')
    {
        i++;
        read(file_store, &character, 1);
        //printf("%c", character);
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
    int file_store, itr;
    char file_name[100];
    cin >> file_name; // enter the filename
    file_store = open(file_name, O_RDONLY);
    char character;
    int i = 0;
    while (read(file_store, &character, 1))
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
    int file_store, itr;
    char file_name[100];
    cin >> file_name; // enter the filename
    file_store = open(file_name, O_RDONLY);
    char character;
    int i = 0;
    while (read(file_store, &character, 1))
    {
        printf("%c", character);
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
    int file_store;
    char file_name[100], character;
    cin >> file_name; // enter the filename
    file_store = open(file_name, O_RDWR);
    int i = 0;
    while (read(file_store, &character, 1))
    {
        printf("%c", character);
        if(character=='a')
        {
            lseek(file_store, -1, SEEK_CUR);
            write(file_store, "K", 1);
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
    int file_store,fd1;
    char file_name_1[100], file_name_2[100], character;
    cin >> file_name_1;
    cin >> file_name_2;
    file_store = open(file_name_1, O_RDONLY); // enter file_name_1 file name
    fd1 = open(file_name_2, O_WRONLY); // enter file_name_2 file name
    char character;
    int i = 0;
    while (read(file_store, &character, 1))
    {
        printf("%c", character);
        write(fd1, &character, 1);
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
    int file_store,fd1;
    char file_name_1[100], file_name_2[100], character;
    cin >> file_name_1;
    cin >> file_name_2;
    file_store = open(file_name_1, O_RDWR);// enter file_name_1 file name
    lseek(file_store, 0, SEEK_END);// enter file_name_2 file name
    fd1 = open(file_name_2, O_RDONLY);
    while (read(fd1, &character, 1))
    {
        write(file_store, &character, 1);
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
    int file_store, k;
    char file_name[100], character;
    cin >> file_name;        // enter file name
    file_store = open(file_name, O_RDONLY);
    int i = lseek(file_store, 0, SEEK_END);
    int j = 1;
    while (i > 0)
    {
        lseek(file_store, -j, SEEK_END);
        read(file_store, &character, 1);
        printf("%c", character);
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
    int file_store, k;
    char file_name[100], character;
    cin >> file_name; // enter the file name
    cin >> k; // enter the number
    file_store = open(file_name, O_RDWR);
    lseek(file_store, -k, SEEK_END);
    read(file_store, &character, 1);
    char temp1 = character;
    lseek(file_store, k - 1, SEEK_SET);
    read(file_store, &character, 1);
    char temp2 = character;
    lseek(file_store, k - 1, SEEK_SET);
    write(file_store, &temp1, 1);
    lseek(file_store, -k, SEEK_END);
    write(file_store, &temp2, 1);
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
    int file_store, fd1;
    char file_name_1[100],file_name_2[100],character;
    cin >> file_name_1; // enter file_name_1
    cin >> file_name_2;// enter file_name_2
    file_store = open(file_name_1, O_RDONLY);
    fd1 = open(file_name_2, O_WRONLY);
    int i = lseek(file_store, 0, SEEK_END);
    int j = 1;
    while (i > 0)
    {
        lseek(file_store, -j, SEEK_END);
        read(file_store, &character, 1);
        write(fd1, &character, 1);
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
    int file_store;
    char file_name[100], character;
    string s;
    cin >> file_name;// enter file name
    cin >> s;// enter string
    file_store = open(file_name, O_RDWR);
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


#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int file_store;
    char file_name[100], character;
    cin >> file_name;// enter filename
    string s;
    file_store = open(file_name, O_RDWR);
    int len = lseek(file_store, 0, SEEK_END);
    int i = len;
    lseek(file_store, 0, SEEK_SET);
    while (i > 0)
    {
        read(file_store, &character, 1);
        s += character;
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

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
int main()
{
    int file_store, fd1;
    char file_name_1[100], file_name_2[100], character;
    cin >> file_name_1; // enter file name
    file_store = open(file_name_1, O_RDWR);
    lseek(file_store, 0, SEEK_SET);
    int j = 0;
    while (read(file_store, &character, 1))
    {
        file_name_2[j] = character;
        j++;
        file_name_2[j] = 'x';
        j++;
    }
    lseek(file_store, 0, SEEK_SET);
    int i = 0;
    while (i < j - 1)
    {
        char temp = file_name_2[i];
      //  printf("%c", temp);
        write(file_store, &temp, 1);
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
    int file_store;
    char file_name[100], character;
    cin >> file_name; // enter file name
    file_store = open(file_name, O_RDONLY);
    lseek(file_store, -1, SEEK_END);
    int num = 0, place = 1;
    while (read(file_store, &character, 1))
    {
        if (character == ' ')
        {
            break;
        }
        else
        {
            num += (character - '0') * place;
            place *= 10;
            lseek(file_store, -2, SEEK_CUR);
        }
    }
    printf("%d", num);
    printf("\n");
}


