#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<unordered_map>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(size_t i=a;i<b;i++)
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
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
    inpt(n);cinbuffer;
    vi v = input1l();
    vi v0, v1, v2;
    For(i, 0, v.size()) {
        if(v[i] % 3 == 0) v0.pb(v[i]);
        if(v[i] % 3 == 1) v1.pb(v[i]);
        if(v[i] % 3 == 2) v2.pb(v[i]);
    }
    //deb(v0.size());deb(v1.size());deb(v2.size());
    int spacebtv1 = v1.size() - 1;
    int spacebtv2 = v2.size() - 1;
    int max0poss = spacebtv1 + spacebtv2 + 3;
    if(v0.size() > max0poss){
        cout<< " No";
    } else cout << "Yes";
}

int32_t main() {
    inpt(t);
    while(t--) {
        sol();
    }
}