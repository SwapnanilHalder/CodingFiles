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

void sol() {
    inpt(n); cinbuffer;
    vi arr = input1l();
    int count=1;
    vector<int> store;
    store.pb(arr[0]);
    For(i, 1, n) {
        store.pb(arr[i]);
        if(store.size() == 2) {
            if(store[0] == store[1]) {
                count += 2;
                store.erase(store.begin());
                continue;
            }
        }
        if(store.size() == 3) {
            if (  (  (store[2] - store[1])*(store[1]-store[0])* (store[0]-store[2])  )  == 0 ) {
                count += 2;
            }

            if(  (  (store[2] - store[1])*(store[1]-store[0])  )  > 0 ) {
                count += 2 ;
                store.erase(store.begin());
            }
            else if (  (  (store[2] - store[1])*(store[1]-store[0])* (store[0]-store[2])  )  > 0 ) {

            }
        }
        if(find(all(store), arr[i]) != store.end()) {
            count += (store.size() *(store.size()+1) )/2 - (store.size() *(store.size()-1) )/2 ; 
            store.erase(store.begin());
            pv(store);
            continue;
        }
    }
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}