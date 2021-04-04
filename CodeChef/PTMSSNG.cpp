#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define ll long long
#define int long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << #x << "=" << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, a) for(const auto &it = a.begin(); it != a.end(); it++)
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}

vi input1l()
{
    vi input(0);
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while (getline(X, num, ' '))
    {
        input.pb(stoi(num));
    }
    //pv(input);
    return input;
}

bool sortcol0(const vector<int> &v1, const vector<int> &v2) {
    return v1[0] < v2[0];
}
bool sortcol1(const vector<int> &v1, const vector<int> &v2) {
    return v1[1] < v2[1];
}

int oddone(vi2d v, int l, int ind) {
    int con = v[0][ind], count = 1;
    //deb(ind);
    int i = 1;
    for(; i<l; i++) {
        if(con != v[i][ind]) {
            if (count %2 != 0) {
                // cout << "if (count %2 != 0)  ";
                // deb(i);deb(con);deb(count);deb(v[i][ind]);
                return con;
            }
            else {
                count = 1;
                con = v[i][ind];
                // cout << "count = 1  ";
                // deb(i);deb(con);deb(count);deb(v[i][ind]);
            }
        }
        else {
            count++;
            // cout << "count++   ";
            // deb(i);deb(con);deb(count);deb(v[i][ind]);
        }
    }
    if (count %2 != 0) {
        // cout << "if (count %2 != 0)  ";
        // deb(i);deb(con);deb(count);
        return con;
    }
}


void sol()
{
    inpt(n);
    cinbuffer;
    vi2d v;
    int l = 4 * n - 1;
    For(i, 0, l) {
        v.pb(input1l());
    }
    sort(all(v), sortcol0);
    //pv2d(v);
    vi ans(2);
    ans[0] = oddone(v, l, 0);
    //deb(ans[0]);
    sort(all(v), sortcol1);
    //pv2d(v);
    ans[1] = oddone(v,l,1);
    pv(ans);
}

int32_t main()
{
    inpt(t);
    while (t--)
    {
        sol();
    }
}