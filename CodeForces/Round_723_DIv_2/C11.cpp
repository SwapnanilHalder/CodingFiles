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

// vi dp;
vi arr;
int n;

// int recur(int sum,int counts, int i, vi dp) {
//     deb(sum); deb(counts); deb(i); pv(dp); deb(n);
//     if(i == n) {
//         return dp[i-1];
//     }
//     // if(dp[i] != -1) {
//     //     return dp[i];
//     // }
//     if(arr[i] >= 0) {
//         if(i>0) dp[i] = dp[i-1] + arr[i];
//         else dp[i] = arr[i];
//         recur(dp[i], counts+1, i+1, dp);
//     }
//     else {
//         if(sum + arr[i-1] < 0) {
//             if(i > 0)dp[i] = dp[i-1];
//             else dp[i] = 0;
//             recur(dp[i], counts, i+1, dp);
//         }
//         else {
//             if(i > 0)dp[i] = dp[i-1] + arr[i];
//             else dp[i] = arr[i];
//             recur( dp[i], counts++, i+1, dp) ;
//             dp[i] -= arr[i]; 
//             recur(dp[i], counts, i++, dp) ;
//         }
//     }
//     return dp[i];
// }

// void recur(int sum,int counts, int i,vi dp, vi &count) {
//     if (i == n) {
//         return;
//     }
//     if (i == 0) {
//         if(arr[i] >=0 ) {
//             counts++;
//             count[counts] = arr[i];
            
//             recur(arr[i], 1, 1, dp, count);
//         }
//         else {
//             recur(0, 0, 1, dp, count);
//         }
//     }
//     else {
//         if(arr[i] >= 0) {
//             counts++;
//             count[counts] = max(count[counts-1]+ arr[i], count[counts]);
//             sum += arr[i];
//             recur(sum, counts, i+1, dp, count);
//         }
//         else {
//             if(sum + arr[i] < 0) {
//                 recur(sum, counts, i+1, dp, count);
//             }
//             else {
//                 counts++;
//                 count[counts] = max(count[counts], count[counts-1] + arr[i]);
//                 recur(sum+arr[i], counts, i+1 , dp, count);
//                 recur(sum, counts-1, i+1, dp, count);
//             }
//         }
//     }        
// }

void checked(int x, map<int, int> &dp) {
    // pl("ENtered");
    // pl(dp.size());
    map<int, int> dp1;
    if(x >=0) {
        if(dp.empty()) {
            dp1.insert(pair<int, int> {1,x});
            // pmint(dp1);
        }
        else {
            loop(it, dp) {
                dp1.insert(pair<int, int> {(it->first)+1, max((it->second) + x, dp1[(it->first) + 1])} );
                // dp.erase(it->first);
                // pmint(dp1);
            }
        }
    }
    else {
        if(dp.empty()) {

        }
        else {
            loop(it, dp) {
                dp1.insert(pair<int, int> {it->first, max(it->second, dp1[it->first])});
                if ( (it->second + x) >=0) {
                    dp1.insert(pair<int, int> {it->first+1, max(it->second + x, dp1[(it->first) +1] ) });
                }
                    
                // pmint(dp1);
            }
        }

    }
    pmint(dp1);
    dp = dp1;
}

void sol() {
    // pl("Started");
    cin >> n;
    cinbuffer;
    arr.clear();
    arr = input1l();
    // pl("Taken");
    // dp.clear();
    // dp = vi(n+2, -1);
    map<int, int> dp;
    // pl("1");
    // pl("2");
    For(i, 0, n) {
        checked(arr[i], dp);
    }
    int max = -INF;
    loop(it, dp) {
        if(it->first > max) {
            max = it->first;
        }
    }

    cout << max << endl;
    return;
}

int32_t main() {
    SPEED1;
    // inpt(t); 
    // while(t--) {
    //     sol();
    // }
    sol();
}

    // if( arr[i] >= 0) {
    //     dp[i] = max(dp[i], arr[i-1] + 1);
    //     sum += arr[i];
    //     counts++;
    //     recur(sum, counts, i+1);
    // }
    // else {
    //     if(sum + arr[i] <0) {
    //         recur(sum, counts, i+1);
    //     }
    //     else {
    //         recur(sum + arr[i], counts++, i+1);
    //         recur(sum, counts, i++);
    //     }
    // }