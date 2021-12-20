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
    string a,s; cin >>a >> s;
    int na = a.size(), ns = s.size();
    if(na > ns) {
        pl("-1"); return;
    }
    int ia=na-1, is = ns-1;
    string b;
    int aa, ss;
    while(ia>=0 && is>= 0) {
        aa = a[ia] - '0';
        ss = s[is] -'0';
        if(ss < aa) {
            is--;
            ss += (s[is]-'0')*10;
        }
        // deb(ss); deb(aa);
        if((ss-aa) > 9 or (ss-aa) < 0 ) {
            pl("-1"); return;
        }
        b.pb(ss-aa+'0');
        // deb(b);
        is--; ia--;
    } 
    if(ia != -1) {
        pl("-1"); return;
    }
    while(is != -1) {
        b.pb(s[is]);
        is--;
    }
    reverse(all(b));
    stringstream geek(b);
 
    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    geek >> x;
    pl(x);
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}