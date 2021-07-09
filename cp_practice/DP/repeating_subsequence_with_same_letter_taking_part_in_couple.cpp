

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <numeric>
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
using namespace std;



int anyTwo(string a) {
    int s = a.size();
    int maxm = INT_MIN;
    vector<vector<int>> dp(s+1, vector<int> (s+1, 0));
    for(int i=1; i<= s; i++) {
        for(int j = i+1; j<= s; j++) {
            if(a[i-1] == a[j-1]) {
                dp[i][j] = dp[i-1][j-1] +1 ;
                if(dp[i][j] > maxm) maxm = dp[i][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(dp[i][j] > maxm) maxm = dp[i][j];
            }
        }
    }
    // pv2d(dp);
    return (maxm > 1);
}

int main() {
    string str = "abba";
    int ans = anyTwo(str);
    cout << "The answer is : " << ans << endl;
}
