#include <bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEEDYY ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vector_int vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pushh push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define int long long
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define only_input(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define print_line(x) cout << x << endl
#define all(v) v.begin(),v.end()

template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Minimum(T x,T y){return (y>x)?x:y;}



using namespace std;

class solve {
public:
    void sol(){
        only_input(n);
        string s;
        cin >> s;
        int ones{0};
        int zeros{0};
        For(i, 0, n){
            if(s[i]=='0') {
                zeros += 1;
            }
            else {
                ones += 1;
            }
        }
        vector_int positionss;
        int g = sqrt(n);
        For(i, 0, g) {
            if( (n % (i+1)) == 0){
                positionss.pushh(i+1);
                if(n/ (i+1) != (i+1)){
                    positionss.pushh(n/(1+i));
                }
            }
        }
        int ans = 1e9;
        For(k, 0, positionss.size() ){
            vector_int vectorss(positionss[k]);
            int query =  n/ (positionss[k]);
            For(i, 0, positionss[k]){
                for(int j=i; j < n; j += positionss[k]){
                    if( (s[j]-'1') == 0)
                        vectorss[i]++;
                }
            }
            For(i, 0, positionss[k]) {
                int anssss = query-vectorss[i];
                anssss = anssss + (ones-vectorss[i]);
                ans = Minimum(ans, anssss);
            }

        }
        print_line(ans);
    }
};


int32_t main() {
    SPEEDYY;
    only_input(t); 
    solve sol1 ;
    while(t--) {
        sol1.sol();
    }
}

