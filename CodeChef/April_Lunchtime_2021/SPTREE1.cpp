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

void solve(vi2d &store, vi &special, int now, vi &score, vi &specials, int step) {
    if(store[now].size() == 0) {
        return;
    }
    
}

void sol() {
    inpt(n); inpt(s); inpt(fixed); cinbuffer;
    vi special = input1l();
    vi2d store (n+1, vi());
    int x{0}, y{0};
    For(i, 0, n-1) {
        cin >> x >> y;
        store[x].pb(y);
        store[y].pb(x);
    }
    // g.printAdj();
    vi score(n+1, 0);
    vi specials(n+1, 0);
    score[fixed] = 0;
    specials[fixed] = special[0];
    int left = n-1;
    int now = fixed;
    solve(store,special, now, score, specials, 0);
    // while(left >0) {
    //     now = store[fixed][0];
    //     if(find(all(special), now) == special.end()) {
    //         score[now] = 
    //     }
    // }

}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}