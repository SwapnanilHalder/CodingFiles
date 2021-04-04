#include <iostream>
#define For(i,a,b) for(int i=a;i<b;i++)
#define END cout<<"\n"
#define deb(x) cout << '\t'<<#x << " = " << x << endl

using namespace std;

int gcd(int a, int b) {
    // cout << "Entered : "<<a << " , " << b<<endl;
    // if(b==0){
    //     return a;
    // }
    // int p = a%b;
    // return euclidean_gcd(b, p);
    return b ? gcd(b, a % b ) : a;
}

int main() {
    cout << "Calculating GCD of two numbers a and b :\n";
    int a, b;
    cout << "Enter a and b : ";
    cin >> a >> b;
    int ans = gcd(a,b);
    deb(ans);
    return 0;
}