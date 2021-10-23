#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back


using namespace std;

class Solution {
public:

    vector<string> findAllWords(string &a)
    {
        vector<string> vec;
        For(i, 0, a.size())
        {
            vec.pb(a.substr(0, i) + a.substr(i+1, a.size()-i-1));
        }
        return vec;
    }
    
    int longestStrChain(vector<string>& words)
    {
        vector<vector<string>> levels(17);
        for (auto &word : words)    levels[word.size()].pb(word);
        
        unordered_map<string, int> mp;
        for (auto word: words)  mp[word] = 1;
        
        int ans = 1;
        For(i, 2, 17)
        {
            for (int j=0; j<levels[i].size(); ++j)
            {
                vector<string> diffWords = findAllWords(levels[i][j]);
                
                for (auto word: diffWords) {
                    if (mp.find(word) != mp.end())  mp[levels[i][j]] = max(mp[word] + 1, mp[levels[i][j]]);
                }
                
                ans = max (ans, mp[levels[i][j]]);
            }
        }
        
        return ans;
    }
};


int main() {
    Solution mySolution;
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.longestStrChain(words) << endl;
}


/*

#include <iostream>
#include <string>
#include <sstream>
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
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
    
}

int32_t main() {
    // system("clear");
    inpt(t);
    while(t--) {
        sol();
    }
}


*/