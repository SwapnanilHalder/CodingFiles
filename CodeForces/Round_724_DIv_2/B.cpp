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

int check(string &str, string &ans, int len) {
    // string temp = "";
    // For(i, 0, len) {
    //     temp.pb(str[i]);
    // }
    // deb(ans);


    int succ = 1;
    For(i, 0, str.size()-len+1) {
        succ = 1;
        For(j, 0, len) {
            // pl(str[i+j]);
            if(str[i+j] != ans[j]) {
                succ = 0;
                break;
            }
        }
        if(succ == 1) {
            return 0;
        }
    }
    return 1;

    // return 0;
}

bool sum(string &ans) {
    // int total = 0;
    // For(i, 0, ans.size()) {
    //     total += (ans[i] - 'a' + 1);
    // }
    // return total;
    For(i, 0, ans.size()) {
        if(ans[i] != 'z') {
            return 1;
        }
    }
    return 0;
}

void generated(string &str, string &ans, int len) {
    int checked = 0;
    checked = check(str, ans, len);
    // deb(checked);
    int count = 0;
    while(checked != 1 && count < 3000) {
        count++;
        if(ans[ans.size()-1] == 'z') {
            if(sum(ans) == 0) {
                ans = "";
                len++;
                For(i, 0, len) {
                    ans.pb('a');
                }
            }
            else {
                ford(i, ans.size()-1, 0) {
                    if(ans[i] == 'z') {
                        ans[i] = 'a';
                    }
                    else {
                        ans[i] += 1;
                        break;
                    }
                }
            }
        }
        else {
            ans[ans.size()-1] += 1;
        }
        // pl(ans);
        checked = check(str, ans, len);
    }
}

void sol() {
    inpt(n);
    string str;
    cin >> str;
    string ans ="a";
    generated(str, ans, 1);
    // pl("DONE");
    pl(ans); return;
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}