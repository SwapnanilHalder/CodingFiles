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
#include <unordered_map>
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
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define loop(it, v) for(auto it = v.rbegin(); it != v.rend(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->ss;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.ss << ")";END
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

// bool cmp(pair<int, int>& a,  pair<int, int>& b)
// {
//     return a.ss > b.ss;
// }

void sol(int t) {
    inpt(n); inpt(c);
    map<int, int> mapped;
    vector<pair<int, int>> range;
    int start=0, end = 1;
    int x, y;
    For(i, 0, n) {
        cin >> x >> y;
        range.pb({x+1, 1});
        range.pb({y, -1});
    }
    sort(all(range));
    For(i, 0, range.size()) {
        mapped[start] += range[i].ff - end;
        start += range[i].ss;
        end = range[i].ff;
    }
    int ans = n;
    if(c!= 0) {
        loop(it, mapped) {
            if(c >=it->ss ) {
                ans += (it->ss) * (it->ff);
                c -= (it->ss);
            }
            else {
                ans += (c * it->ff);
                c = 0;
            }
        }

    }

   
    cout <<"Case #" << t << ": " <<  ans << endl;

}

int32_t main() {
    SPEED1;
    inpt(t); 
    For(i, 0, t) {
        sol(i+1);
    }
}

/*


 vector<int> count(k+2, 0);
    For(i, 0, n) {
        count[range[i].ff]++;
        count[range[i].ss+1]--;
    }
    For(i, 1, k+1) {
        count[i] += count[i-1];
    }
    vector<pair<int, int>> finally;
    For(i, 1, k+1) {
        finally.pb({count[i], i});
    }
    sort(all(finally), greater<pair<int, int>>());
    int cut=0, answer = 0;
    For(i, 0, n) {
        if(cut == c) {
            break;
        }
        if(   (finally[i].ff - start[finally[i].ss]   - end[finally[i].ss]) > 0 ) {
            answer += (finally[i].ff - (start[finally[i].ss]   + end[finally[i].ss]));
            cut++;
        }
    }
    // deb(answer);


*/