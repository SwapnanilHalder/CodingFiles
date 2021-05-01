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

void sol(int t) {
    inpt(n); inpt(A); inpt(B); cinbuffer;
    vi arr (10, 0);
    For(i, 0, n) {
        cin >> arr[i];
    }
    int i = 2;
    while(1) {
        if(arr[i-1] >= arr[i-2]) {
            arr[i] += arr[i-2];
            arr[i-1] -= arr[i-2];
            arr[i-2] = 0;
        }
        else {
            arr[i] += arr[i-1];
            arr[i-2] -= arr[i-1];
            // arr[i] += (arr[i-2]+1)/2;
            arr[i-1] = 0;
            arr[i-1] = arr[i-2];
            arr[i-2] = 0;
        }
        pv(arr);
        i++;
        if(accumulate(all(arr), 0) == 1) {
            break;
        }
    }
    int count=0, last = 0, ans = 0;
    ford(i, n+1, 0) {
        if(arr[i] != 0) {
            cout << "Case #" << t << ": " << i+1<<endl;
            return;
        }
    }
    // ans = last + 2*ceil((log(count) / log(2)));
    // pl(ans);
}

int32_t main() {
    // system("clear");
    inpt(t);
    For(i, 1, t+1) {
        sol(i);
    }
}