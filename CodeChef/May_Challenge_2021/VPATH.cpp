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
#define int long long int
#define END cout<<"\n"
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define sz(a) (int)(a.size())
#define rz resize
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()

#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
using namespace std;

vi input1l(){
    vi input(0);
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while(getline(X, num, ' ')) {
        input.pb(stoll(num));
    }
    //pv(input);
    return input;
}

int ans;
vi2d v;
vi dp, tot;

void dfs(int cur, int par) {
    dp[cur] = 1, tot[cur] = 1;
    int sum = 0, cnt = 0;
    For(i, 0, sz(v[cur])) {
        int node = v[cur][i];
        if(node != par) {
            dfs(node, cur);dp[cur] += ((2*dp[node]) % MOD), dp[cur]%= MOD, cnt++, tot[cur] += tot[node], tot[cur]%=MOD, tot[cur]+= dp[node], tot[cur] %= MOD;
            sum += dp[node];
        }
    }
    For(i, 0, sz(v[cur])) {
        int node = v[cur][i];
        if(node != par) {
            tot[cur] += (dp[node] * ((sum - dp[node] + MOD) % MOD)) % MOD;
            tot[cur] %= MOD;
        }
    }
}

void sol() {
    ans = 0;
    inpt(n);
    v.rz(n+1), dp.rz(n+1), tot.rz(n+1);
    For(i, 0, n-1) {
        inpt(l); inpt(r);
        v[l].pb(r), v[r].pb(l);
    }
    dfs(1,1);
    int ans = tot[1] % MOD;
    pl(ans);
    dp.clear();
    v.clear();
    tot.clear();
}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}