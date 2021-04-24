#include <iostream>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define END cout<<"\n"
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END


using namespace std;

bool is_prime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

vector<int> primesum(int A) {
    if(A == 4) {
        return vector<int> {2,2};
    }
    else {
        int i = 3;
        while ( i <= A/2) {
            if (is_prime(i)) {
                if(is_prime (A-i)) {
                    return vector<int> {i, A-i};
                }
            }
            i += 2;
        }
    }
}

int main() {
    int n = 378;
    pv(primesum(n));
}