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
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " :  " << itr->second;END;}
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

/*
1
8
1 1 1 2 3 3 3 3
1 2 2 2 4 4 4 4
*/

void store(vi &n1sw, vi &n2sw, int num, int n1count, int n2count) {
    if(n1count > n2count) {
        For(i, 0, (n1count-n2count)/2) n1sw.pb(num);
    } else {
        For(i, 0, (n2count-n1count)/2) n2sw.pb(num);
    }
}

void sol() {
    inpt(n);cinbuffer;
    unordered_map<int, int> n1;
    unordered_map<int,int> n2;
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while(getline(X, num, ' ')) {
        n1[stoll(num)]++;
    }
    getline(cin, str);
    stringstream Y(str);
    while(getline(Y, num, ' ')) {
        n2[stoll(num)]++;
    }
    pmint(n1);
    pmint(n2);
    deb(n1.size());
    int count{0};
    vi n1sw, n2sw;
    int success{1};
    auto itr = n1.begin();
    while(n1.size() > 0) {
        if( (n1[itr->first] + n2[itr->first]) % 2 != 0) {success = 0; break;}
        else {
            count += abs( n1[itr->first]-n2[itr->first] ) / 2;
            store(n1sw, n2sw, itr->first, n1[itr->first], n2[itr->first]);
            n1.erase(itr->first);
            n2.erase(itr->first);
            itr = n1.begin();
        }
        deb(n1.size());
    }
    pmint(n1);pmint(n2);
    deb(count);deb(success);
    pl("n1 is done");
    itr = n2.begin();
    while(n2.size() > 0) {
        if(itr->second %2 != 0){success = 0; break;}
        store(n1sw, n2sw, itr->first, n1[itr->first], n2[itr->first]);
        count += itr->second/2 ;
        n2.erase(itr->first);
        itr = n2.begin();
    }
    deb(count);deb(success);
    pl("n2 is done");
    pmint(n1);pmint(n2);
    if(success == 0 || count%2 != 0) pl("-1");
    else {
        //pl(count/2);
        sort(all(n1sw)); sort(all(n2sw));
        pv(n1sw);pv(n2sw);
        int total{0}, sum{0};
        int i=0;int j=0;
        while(total < n1sw.size()) {
            total++;
            if(n1sw[i] < n2sw[j]) {
                sum += n1sw[i];
                i++;
            } else {
                sum += n2sw[j];
                j++;
            }
        }
        pl(sum);
    }
}

int32_t main() {
    inpt(t);
    while(t--) {
        sol();
    }
}