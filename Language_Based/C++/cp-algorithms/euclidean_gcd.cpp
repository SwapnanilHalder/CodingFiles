#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, (a % b)) : a;
}

int main() {
    int a{0}, b{0};
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}