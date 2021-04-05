#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<lli>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define ll long long
#define lli unsigned long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define printvec(v) for(const auto &i: v){cout<<i<<" ";}END
#define deb(x) cout << #x << "=" << x << endl
using namespace std;

int main() {
    SPEED;
    int t{0};
    cin >> t;
    cinbuffer;
    For(l, 0, t){
        lli ts{0};
        cin >> ts;
        if((ts & 1) == 1){
            cout << (ts>>1)<< endl;
        } else {
            while((ts & 1) == 0){
                ts /=2;
            }
            cout << (ts>>1)<< endl;
        }
    }
}