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

vector<char> input1l(){
    vector<char> input(0);
    string str, num;
    // getline(cin, str);
    cin >> str;
    // stringstream X(str);
    // while(getline(X, num, ' ')) {
    //     input.pb(stoll(num));
    // }
    For(i, 0, str.size()) {
        input.pb(str[i]);
    }
    //pv(input);
    return input;
}

void sol() {
    inpt(r); inpt(c);
    vector<vector<char>> arr(r, vector<char>(c, 'a'));
    // vector<string> arr(r);
    For(i, 0, r) {
        arr[i] = input1l();
    }
    vector<vector<int>> visited(r, vi(c, 0));
    int i=0, j=0;
    int new_x, new_y;
    // pv2d(arr);
    while(i >= 0 && i< r && j>=0 && j<c) {
        if(visited[i][j] == 1) {
            cout << -1 << endl; return;
        }
        if(arr[i][j] == 'R') {
            new_x=i; new_y=j+1;
        }
        else if(arr[i][j] == 'L') {
            new_x=i; new_y=j-1;
        }
        else if(arr[i][j] == 'U') {
            new_x=i-1; new_y=j;
        }
        else if(arr[i][j] == 'D') {
            new_x=i+1; new_y=j;
        }
        // cout << new_x << " , " << new_y << endl;
        visited[i][j] = 1;
        i=new_x, j=new_y;
        // deb(i); deb(j);
    }
    if(i<0) {
        cout << i+2 << " " << j+1 << endl;
        return;
    }
    if(i == r) {
        cout << i << " " << j+1 << endl;
        return;
    }
    if(j<0) {
        cout << i+1 << " " << j+2 << endl;
        return;
    }
    if(j == c) {
        cout << i+1 << " " << j << endl;
        return;
    }
    // else {
    //     cout << -1 << endl;
    //     return;
    // }
}

int32_t main() {
    SPEED1;
    sol();
    // inpt(t); 
    // while(t--) {
    //     sol();
    // }
}