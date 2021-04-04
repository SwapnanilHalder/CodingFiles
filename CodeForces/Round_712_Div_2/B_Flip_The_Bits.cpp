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
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
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

void sol() {
    inpt(n);
    string str1, str2;
    if (str1.size() != str2.size() || str1.size() %2 != 0 || str2.size() % 2 != 0) {
        pl("NO"); return;
    }
    cin >> str1>>str2;
    int first_0 = 0, second_0 = 0, first_1 = 0, second_1 = 0;
    int matched_before = 1, matched_after = 1;
    For(i, 0, n) {
        if(i % 2 != 0) {
            if(matched_before == matched_after && first_1 == second_1 && first_0 == second_0) {
                first_0 = 0; second_0 = 0; first_1 = 0; second_1 = 0;
            }
        }
        if(str1[i] == '0') {
            first_0++;
        }
        else {
            first_1++;
        }
        if(str2[i] == '0') {
            second_0++;
        }
        else {
            second_1++;
        }
        matched_before = matched_after;
        if(str1[i] != str2[i]) {
            matched_after = 0;
        }
        else {
            matched_after = 1;
        }
    }
    if(first_0 == 0 && second_0 == 0 && first_1 == 0 && second_1 == 0) {
        pl("YES");return;
    }
    else{
        pl("NO"); return;
    }
}

int32_t main() {
    // system("clear");
    inpt(t);
    while(t--) {
        sol();
    }
}