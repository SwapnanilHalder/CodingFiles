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
#define int unsigned long long int
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
#define pl(x) printf("%llu\n", x);
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

pair<int, int> minutes(int y) {
    int zeros = 0, temp = y;
    while(temp > 0) {
        temp >>=1;
        zeros++;
    }
    if(zeros == 1) {
        return {1, 1};
    }
    // deb(zeros);
    int target = (1<< (zeros-1));
    int target1 = (target << 1) -1;
    
    if(target1 == y) {
        return {zeros, y};
    }
    // if(y == (target + 1)) {
    //     return {zeros-1, (target >> 1)-1};
    // }
    // if( (target-1)<<1 == y ){
    //     return {0, 0};
    // }
    // deb(target);
    return {zeros, target-1};
}

void sol() {
    int x, y;
    scanf("%ll", &x);
    scanf("%ll", &y);
    if( (y % x) != 0 ) {
        pl("-1"); return;
    }
    y /= x; x = 1;
    if(y == 2) {
        pl("-1"); return;
    }
    int temp = y, mins = 0; 
    // int count = 0;
    while(temp > 0) {
        if(temp == 2) {
            pl("-1"); return;
        }
        pair<int, int> a = minutes(temp);
        if( (a.second << 1) == temp) {
            pl("-1"); return;
        }
        temp -= a.second;
        mins += a.first;
        // deb(temp); // deb(mins);
        // count++;
    }
    // deb(count);
    // if(count > 2) {
    //     pl("-1"); return;
    // }
    printf("%ll\n", mins);
    return;

}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}