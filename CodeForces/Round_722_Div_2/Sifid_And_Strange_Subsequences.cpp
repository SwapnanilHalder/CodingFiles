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
#define END cout << "\n"
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define inpt(x) int x{}; cin >> x
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
    inpt(n); cinbuffer;
    vi arr = input1l();
    sort(all(arr));
    int now_diff = 0, min_diff = INF, maxm = -INF, count=0;
    vi store = {arr[0]};
    int store_size = 1;
    For(i, 1, n) {
        now_diff = abs(arr[i] - store[store_size-1]);
        if (arr[i] > maxm) {
            maxm = arr[i];
        }
        // deb(now_diff); deb(maxm);
        if(now_diff < min_diff) {
            min_diff = now_diff;
        }
        if(min_diff >= maxm) {
            store.pb(arr[i]);
            store_size++;
        }
        else {
            break;
        }
    }
    pl(store_size); return;
    // pv(store);
    // deb(store_size);
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}