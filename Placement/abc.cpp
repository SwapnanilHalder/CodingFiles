#include <iostream>
using namespace std;

class out {
    int x;
    public:
    class in {
        public:
        in() {
            cout << "Inner Class ";
        }
    };

    out() {
        in t ;
        cout << "Outer Class "; 
    }
};

int main() {
    in t;
    return 0;
}