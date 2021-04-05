#include<iostream>

using namespace std;

int binpow(int &n, int &pow) {
    int a  = n;
    int res = 1;
    while(pow > 0) {
        if(pow & 1) {
            res *= a;
        }
        a *= a;
        pow >>= 1;
    }
    return res;
}

int main() {
    int n{0}, pow{0};
    cin >> n >> pow;
    cout << binpow(n, pow) << endl;
}