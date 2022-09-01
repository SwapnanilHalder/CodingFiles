#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <unordered_map>
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

void sol() {
    inpt(n); inpt(m); inpt(t); cinbuffer;
    vi arr = input1l();
    vi time_left (arr.size());
    // vi2d xy(m, vi(2));
    int a, b;
    unordered_map<int, int> mapp;
    For(i, 0, m) {
        cin >> a >> b;
        mapp[a] = b;
    }
    time_left[0] = t-arr[0];
    if(time_left[0] <= 0) {
            // pv(arr);
            // pv(time_left); END;END;
        cout<< "No" << endl; return;
    }
    For(i, 1, n-1) {
        if(mapp.find(i+1) != mapp.end())
            time_left[i-1] += mapp[i+1];
        time_left[i] = time_left[i-1] - arr[i];
        if(time_left[i] <= 0) {
            // cout << "No : " << i << endl;
            // pv(arr);
            // pv(time_left); END;END;
            cout<< "No" << endl; return;
        }
        // if(mapp.find(i+2) != mapp.end())
        //     time_left[i] += mapp[i-1];
    }
    // pv(arr);
    // pv(time_left);
    pl("Yes"); return;
}

int32_t main() {
    SPEED1;
    // inpt(t); 
    // while(t--) {
    //     sol();
    // }
    sol();
}