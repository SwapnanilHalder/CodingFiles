#include <iostream>

using namespace std;

namespace a {
    char a = 127;
    void aa() {
        cout << a << endl;
    }

}
int main()
{
    a::aa();
    for (char a = 0; a <= 126; a++)
        cout << a << " ";
    cout << endl;
    bool a = true;

    for (a = 1; a <= 5; a++)
        cout << a;


    return 0;
}