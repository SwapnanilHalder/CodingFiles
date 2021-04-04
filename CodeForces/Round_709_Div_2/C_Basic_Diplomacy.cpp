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
    // pl("Entered SOL");
    inpt(n); inpt(m); cinbuffer;
    int limit = ceil((float) (m/2) );
    // deb(limit);
    map<int, int> days;
    For(i, 1, n+1) {
        days[i] = 0;
    }
    vi order;
    // pmint(days);
    vi temp; int min = INF; int min_pos = -1;
    vi2d dp (m, vi(n, 0));
    For(i, 0, m) {
        temp = input1l();
        For(j, 1, temp[0]+1) {
            dp[i][temp[j]-1] = 1;
        }
    }
    pv2d(dp);
    map<int,int> counts;
    int temp_c = 0;
    For(i, 0, n) {
        For(j, 0, m) {
            counts[i+1] += dp[j][i];
        }
    }
    pmint(counts);
    For(i, 0, m) {
        For(j, 0, n) {
            if(dp[i][j] != 0) {
                if(counts[i+1] < min && counts[i+1] != 0) {
                    min = counts[i+1];
                    min_pos = i+1;
                }
            }
        }
        counts[min_pos]--;
        order.pb(min_pos);
    }
    pv(order);



    // For(i, 0, m) {
    //     temp = input1l(); 
    //     min = INF; min_pos = -1;
    //     For(j, 1, temp.size()) {
    //         if(days[temp[j]] == 0) {
    //             days[temp[j]]++;
    //             if(days[temp[j]] > limit ) { pl("NO"); return; }
    //             order.pb(temp[j]);
    //             min = INF; min_pos = -1;
    //             break;
    //         }
    //         else if (days[temp[j]] < min) {
    //             min = days[temp[j]];
    //             min_pos = temp[j];
    //         }
    //     }
    //     if (min_pos != -1) {
    //         days[min_pos]++;
    //         if(days[min_pos] > limit ) { pl("NO"); return; }
    //         order.pb(min_pos);  
    //         min = INF; min_pos = -1;        
    //     }
    //     // pmint(days);
    //     // pv(order);
    // }
    // pl("YES"); pv(order);
    // return;
}

int32_t main() {
    // system("clear");
    inpt(t);
    while(t--) {
        sol();
    }
}