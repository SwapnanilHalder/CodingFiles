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
#define lli long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define printvec(v) for(const auto &i: v){cout<<i<<" ";}END
#define deb(x) cout << #x << "=" << x << endl
#define pl(x) cout << x << endl
using namespace std;

int main() {
    SPEED;
    int t{0};
    cin >>t;
    while (t--) {
        string s;
        cin >> s;
        int count{0};
        For(i, 0, s.length()-1) {
            if(i >=s.length()) break;
            if(s[i] != s[i+1]) {
                count++;
                i++;
            }
        }
        pl(count);
    }
}