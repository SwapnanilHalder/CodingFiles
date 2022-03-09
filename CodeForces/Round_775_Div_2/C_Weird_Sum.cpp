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

int distancesum(vi &arr, int n)
{
    // sorting the array.
    sort(all(arr));
 
    // for each point, finding the distance.
    int res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        res += (arr[i] * i - sum);
        sum += arr[i];
    }
 
    return res;
}
 
int distsum(vi &x, vi &y) {
    int n = x.size();
    return distancesum(x, n) + distancesum(y, n);
}

void sol() {
    inpt(n); inpt(m); cinbuffer;
    vi2d arr(n, vi(m));
    set<int> sett;
    For(i, 0, n) {
        For(j, 0, m) {
            cin >> arr[i][j];
            sett.insert(arr[i][j]);
        }
    }
    int sum=0;
    vi x, y;
    loop(it, sett) {
        x.clear(); y.clear();
        For(i, 0, n) {
            For(j, 0, m) {
                if(arr[i][j] == *it) {
                    x.pb(i); y.pb(j);
                }
            }
        }
        sum += distsum(x, y);
    }
    pl(sum); return;
}

int32_t main() {
    SPEED1;
    int t=1;
    while(t--) {
        sol();
    }
}