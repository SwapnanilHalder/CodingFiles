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

vi reverse_subarray(vi arr, int start, int end) {
    vi arr1;
    For(i, 0, start) {
        arr1.pb(arr[i]);
    }
    ford(j, end, start) {
        arr1.pb(arr[j]);
    }
    For(i, end+1, arr.size()) {
        arr1.pb(arr[i]);
    }
    // pv(arr1);
    return arr1;
}

int check_matched(vi arr, int c, int ind) {
    // inpt(n); cinbuffer;
    int n = arr.size();
    int min{INF}, min_idx{-1}, cost{0};
    For(i, 0, n-1) {
        min = arr[i];
        min_idx = i;
        // pl("NEW ARRAY : "); pv(arr);
        For(j, i, n) {
            if (arr[j] < min) {
                min = arr[j];
                min_idx = j;
            }
        }
        cost += (min_idx-i+1);
        arr = reverse_subarray(arr, i, min_idx);
    }
    if(cost == c) {
        return 1;
    }
    else return -1;
}


void sol(int ind) {
    inpt(n); inpt(c);
    int maxm = ((n * (n+1)) / 2 ) - 1;
    int min = n-1;
    if(c > maxm || c < min) {
        printf("Case #%d: IMPOSSIBLE\n", ind);
        return;
    }
    else {
        vi arr(n, 0);
        For(i, 1, n+1) {
            arr[i-1] = i;
        }
        int checked = -1;
        do {
            checked = check_matched(arr, c, ind);
            if(checked == 1) {
                printf("Case #%d: ",ind);
                pv(arr);
                return;
            }
        } while (next_permutation(all(arr)));
        printf("Case #%d: IMPOSSIBLE\n", ind);
        return;
    }

}

int32_t main() {
    // system("clear");
    inpt(t);
    For(i, 0, t) {
        sol(i+1);
    }
}
