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

void sol(int t) {
    vi2d arr(3, vi(3, 0));
    For(i, 0, 3) {
        cin >> arr[0][i];
    }
    cin >> arr[1][0] >> arr[1][2];
    For(i, 0, 3) {
        cin >> arr[2][i];
    }
    // pv2d(arr);
    int count = 0;
    For(i, 0, 3) {
        if(i == 1) {
            continue;
        }
        if(arr[i][0] + arr[i][1] + arr[i][2]   == 3 * arr[i][1]) {
            count++;
        }
        if(arr[0][i] + arr[1][i] + arr[2][i]   == 3 * arr[1][i]) {
            count++;
        }
    }
    // deb(count);
    int tempinc = 0;
    vi store = {(arr[0][0] + arr[2][2])   , (arr[0][2] + arr[2][0])   , (arr[0][1] + arr[2][1])  , (arr[1][0] + arr[1][2]) };
    map<int, int> st;
    For(i, 0, store.size()) {
        // if( (store[i] % 2 )== 0)
            st[store[i]/2]++;
    }
    int maxm = INT_MIN;
    loop(it, st) {
        if (it->second > maxm) {
            maxm = it->second;
        }
    }
    cout <<"Case #" << t << ": " <<  count + maxm << endl;
}

int32_t main() {
    SPEED1;
    inpt(t); 
    For(i, 0, t) {
        sol(i+1);
    }
}