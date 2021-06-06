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

vi printDivisors(int n)
{
    vi arr;
    // Note that this loop runs till square root
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                arr.pb(i);
 
            else // Otherwise print both
                arr.pb(i); arr.pb(n/i);
        }
    }
    return arr;
}

void sol() {
    inpt(n); 
    string str;
    cin >> str;
    map<char, int> mapped;
    vi ans;
    vector<double> ratio;
    For(i, 0, str.size()) {
        mapped[str[i]]++;
        ratio.pb((double)mapped['D'] / (double)(mapped['K']));
        // pv(ratio);
        if(mapped['K'] == 0) {
            ans.pb(mapped['D']);
        }
        else if(mapped['D'] == 0) {
            ans.pb(mapped['K']);
        }
        else {
            ans.pb(1);
            vi arr = printDivisors(i+1);
            deb(i+1);
            pv(arr);
            pv(ratio);
            For (j, 0, arr.size()) {
                if(ratio[arr.size()-1] == ratio[arr.size()-1 - arr[j]]) {
                    pv(ratio);
                    ans[ans.size()-1] = max(ans[ans.size()-1], ans[arr.size()-1 - arr[j]] + 1);
                }
            }
            
        }
        // else {
            

        //     // if(mapped['D'] == mapped['K']) {
        //     //     ans.pb(mapped['D']);
        //     // }
        //     // else if(mapped['D'] % mapped['K'] == 0) {
        //     //     ans.pb(mapped['K']);
        //     // } 
        //     // else if(mapped['K'] % mapped['D'] == 0) {
        //     //     ans.pb(mapped['D']);
        //     // }
        //     else {
        //         ans.pb(1);
        //     }
        // }
    } 
    pv(ans); return;
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}