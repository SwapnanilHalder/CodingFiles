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
#define deb(x) cout << '\t'<<#x << " = " << x << " ; "
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
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

void sol() {
    inpt(n);
    vi l(n), r(n), c(n);
    vector<pair<int, int>> lc, rc;
    For(i, 0, n) {
        cin >> l[i] >> r[i] >> c[i];
        lc.pb({l[i], c[i]});
        rc.pb({r[i], c[i]});  
    }
    int l_limit = INT_MAX, r_limit = INT_MIN;
    int l_cost=INT_MAX, r_cost=INT_MAX, t_cost=INT_MAX, acc = 0;
    For(i, 0, n) {
        acc = 0;
        if(r[i] == r_limit && l[i] == l_limit) {
            pl("1");
            if(c[i] < (t_cost)) {
                t_cost = c[i];
            }
        }
        else if(r[i] >= r_limit && l[i] <= l_limit) {
            pl("2");
            r_limit = r[i];
            l_limit = l[i];
            t_cost = c[i];
            if(r[i] > r_limit) {
                r_cost = INT_MAX;
            }
            if(l[i] > l_limit) {
                l_cost = INT_MAX;
            }
        }
        else {
            if(l[i] < l_limit) {
                acc = 1;
                l_limit = l[i];
                l_cost = c[i];
            }
            if(l[i] == l_limit) {
                l_cost = min(c[i], l_cost);
            }
            if(r[i] > r_limit) {
                acc = 1;
                r_limit = r[i];
                r_cost = c[i];
            }
            if(r[i] == r_limit) {
                r_cost = min(c[i], r_cost);
            }
            if(acc == 1) t_cost = min(t_cost, l_cost + r_cost);
        }

        deb(r_limit); deb(l_limit); deb(t_cost); deb(r_cost); deb(l_cost); deb(r[i]); deb(l[i]); deb(c[i]);END;
        pl(t_cost);
    }
    return;
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}