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
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "\t(" << v.first << " , " << v.second << ")\n";
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
void alma_move(set<pair<int, int> > s1, pair<int, int> a_pos, pair<int, int> b_pos, int a_move, int b_move);
void berthe_move(set<pair<int, int> > s1, pair<int, int> a_pos,pair<int, int> b_pos, int a_move, int b_move);
int max_diff = -INF;

void alma_move(set<pair<int, int> > s1, pair<int, int> a_pos,pair<int, int> b_pos, int a_move, int b_move) {
    // pl("Entered Alma");
    s1.erase(a_pos);
    s1.erase(b_pos);
    pair<int, int> x1, x2, x3;
    if (a_pos.second %2 == 0) {
        x1 = make_pair(a_pos.first-1, a_pos.second-1);
        x2 = make_pair(a_pos.first, a_pos.second-1);
        x3 = make_pair(a_pos.first, a_pos.second+1);
    }
    if (a_pos.second %2 != 0) {
        x1 = make_pair(a_pos.first+1, a_pos.second+1);
        x2 = make_pair(a_pos.first, a_pos.second-1);
        x3 = make_pair(a_pos.first, a_pos.second+1);
    }
    if(s1.find(x1) != s1.end()) {
        berthe_move(s1, x1, b_pos, a_move+1, b_move);
    }
    else if(s1.find(x2) != s1.end()) {
        berthe_move(s1, x2,b_pos, a_move+1, b_move);
    }
    else if(s1.find(x3) != s1.end()) {
        berthe_move(s1, x3,b_pos, a_move+1, b_move);
    }
    else {
        alma_move(s1, x1,b_pos, a_move+1, b_move);
        alma_move(s1, x2,b_pos, a_move+1, b_move);
        alma_move(s1, x3,b_pos, a_move+1, b_move);
    }

    if(s1.empty()) {
        if(max_diff < (a_move-b_move)) {
            max_diff = (a_move-b_move);
        }
        return;
    }
}

void berthe_move(set<pair<int, int> > s1, pair<int, int> a_pos,pair<int, int> b_pos, int a_move, int b_move) {
        pl("Entered berthe");
    s1.erase(a_pos);
    s1.erase(b_pos);
    pair<int, int> x1, x2, x3;
    if (a_pos.second %2 == 0) {
        x1 = make_pair(b_pos.first-1, a_pos.second-1);
        x2 = make_pair(b_pos.first, a_pos.second-1);
        x3 = make_pair(b_pos.first, a_pos.second+1);
    }
    if (a_pos.second %2 != 0) {
        x1 = make_pair(b_pos.first+1, a_pos.second+1);
        x2 = make_pair(b_pos.first, a_pos.second-1);
        x3 = make_pair(b_pos.first, a_pos.second+1);
    }
    if(s1.find(x1) != s1.end()) {
        alma_move(s1, a_pos, x1, a_move, b_move+1);
    }
    if(s1.find(x2) != s1.end()) {
        alma_move(s1,a_pos, x2, a_move, b_move+1);
    }
    if(s1.find(x3) != s1.end()) {
        alma_move(s1,a_pos, x3, a_move, b_move+1);
    }
    if(s1.empty()) {
        if(max_diff < (a_move-b_move)) {
            max_diff = (a_move-b_move);
        }
        return;
    }
}

int casef = 1;
void sol() {
    inpt(s);
    pair<int, int> A1, B1;
    cin >> A1.first >> A1.second>> B1.first >> B1.second;
    inpt(c);cinbuffer;
    vi2d v;
    For(i,0,c) {
        v.pb(input1l());
    }
    set<pair<int, int> > s1;
    For(i, 1, s+1) {
        For(j, 1, 2*i) {
            pair<int, int> x = make_pair(i, j);
            s1.insert(x);
            cout << x.first<< " , " << x.second<<endl;
        }
    }pl("ED");
    For(i, 0, v.size()) {
        pl("ET pair");
        pair<int, int> x;
        x.first = v[i][0];
        x.second  = v[i][1];
        pl("pair crt");
        cout << x.first<< " , " << x.second<<endl;
        s1.erase(x);
    }
    alma_move(s1, A1,B1, 1, 1);
    cout << max_diff<<endl;
}

int32_t main() {
    // system("clear");
    inpt(t);
    while(t--) {
        sol();
    }
}