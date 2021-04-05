#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
#include <chrono>
#include <numeric>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define int long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << (itr->second).first << " , " << (itr->second).second ;END;}
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

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

bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
    if(a.second.first > b.second.first) return false;
    else if(a.second.first < b.second.first) return true;
    else return (a.second.second < b.second.second); 
}

int casef = 1;
void sol() {
    inpt(n); inpt(x); cinbuffer;
    vi v = input1l();
    map<int, pair<int, int>> turn_pos;
    For(i, 0, v.size()) {
        int turn = (v[i] % x == 0) ? v[i]/x : (v[i]/x)+1;
        turn_pos[i+1] = make_pair(turn, i+1);
    }
    // pmint(turn_pos);
    vector<pair<int, pair<int, int>>> A;
    for(auto &it: turn_pos) {
        A.pb(it);
    }

    sort(all(A), cmp);
    cout << "Case #" << casef << ": ";
    casef ++;
    loop(it, A) {
        cout << it->first << " ";
    }END;
}

int32_t main() {
    // system("clear");
    inpt(t);
    while(t--) {
        sol();
    }
}