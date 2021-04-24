#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

vi input1l() {
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

int countDigit(int n) {
  return floor(log10(n) + 1);
}

void sol(int ind) {
    // inpt(n); cinbuffer;
    inpt(n); cinbuffer;
    vi arr = input1l();
    int total = 0, prev_digit = 0,res_digit=0, now_digit = 0, min_Temp = 0, max_Temp =0;
    For(i, 0, n-1) {
        min_Temp = arr[i+1]; 
        max_Temp = arr[i+1];
        prev_digit = countDigit(arr[i]);
        now_digit = countDigit(arr[i+1]);
        res_digit = now_digit;

        while(now_digit < prev_digit) {
            min_Temp *= 10;
            max_Temp = min_Temp + 9;
            now_digit++;
        }
        if(max_Temp <= arr[i] ) {
            max_Temp = arr[i+1] * pow ( 10, prev_digit+1-res_digit);
            arr[i+1] = max_Temp;
            deb(arr[i+1]);
            total += (now_digit+1 - res_digit);
        }
        else {
            total += (now_digit - res_digit);
            if (min_Temp > arr[i]) {
                arr[i+1] = min_Temp;
                deb(arr[i+1]);
            }
            else {
                min_Temp = arr[i] + 1;
                arr[i+1] = min_Temp;
                deb(arr[i+1]);
            }
        }
    }
    pv(arr);
    cout << "Case #"<<ind<<": "<<total<<endl;
    return;
}

int32_t main() {
    // system("clear");
    inpt(t); 
    cinbuffer;
    For(i, 0, t) {
        sol(i+1);
    }
}