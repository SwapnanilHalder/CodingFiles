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
#define END cout<<"\n"
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
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

void sol() {
    string str1, str2;
    cin >> str1 >> str2;
    vi2d dp (str1.size()+1, vi (str2.size()+1, 0));
    string ans = "";
    int len = 0;
    For(i, 1, str1.size() +1) {
        For(j, 1, str2.size()+1) {
            if(str1[i-1] == str2[j-1]) {

                dp[i][j] = dp[i-1][j-1] + 1;
                // if (dp[i][j] > ans.size()) {
                //     cout << "Adding : " << str1[i-1] <<" , "<< str1[i] << " : " << str2[j-1]  << " :: " << i << ".." << j<<endl;
                //     ans.pb(str1[i-1]);
                //     len++;
                // }
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // pv2d(dp);
    // deb(ans);
    // deb(len);
    int index = dp[str1.size()][str2.size()];
    vector<char> lcs (dp[str1.size()][str2.size()]);
    int i = str1.size(), j = str2.size();
    while (i>0 && j > 0) {
        if (str1[i-1] == str2[j-1]) {
            lcs[index-1] = str1[i-1];
            i--; j--; index--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    // pv(lcs);
    string answer (all(lcs));
    pl(answer);
    return;
}

int32_t main() {
    SPEED;
    sol();
}