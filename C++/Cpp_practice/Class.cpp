#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class nameid
{
private:
    string name;

public:
    void setName(string x)
    {
        name = x;
    }

    string getName()
    {
        return name;
    }
};

int main()
{
    char myname[100];
    puts("Enter the name:");
    gets(myname);
    nameid me;
    me.setName(myname);
    cout << me.getName() << endl;
    main();
}
