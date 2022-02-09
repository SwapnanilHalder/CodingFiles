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