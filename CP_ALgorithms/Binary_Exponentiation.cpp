#include <iostream>
#define For(i,a,b) for(int i=a;i<b;i++)
#define END cout<<"\n"
#define deb(x) cout << '\t'<<#x << " = " << x << endl

using namespace std;

int main() {
    cout <<"We are calculating a^b in O(log n) time \n";
    int a, b;
    cout << "Enter a and b : ";
    cin >> a >> b;
    long long int ans {1};
    while(b > 0) {
        if (b & 1) {
            // deb(b);
            ans *= a;
            // deb(ans);
        }
        a *= a;
        b >>= 1;
        
    }
    cout << "Answer : " << ans << endl;
}