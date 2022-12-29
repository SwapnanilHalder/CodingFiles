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

void solve() {
    string s; cin >> s;
    int n = s.size();
    inpt(q);
    
    vi2d a(26, vi (n+1, 0));
    for(int i=0; i<n; i++){
        a[s[i] - 'a'][i+1]++;
    }
    
    for(int i=0; i<26; i++){
    		for(int j=1; j<=n; j++){
        		a[i][j] += a[i][j-1];
        }
    }
    
    int count = 0;
    while(q--){
        inpt(left); inpt(right);
        
        if((right - left + 1)%2 == 0)
            continue;
        
        int cnt = 0;
        string odd = "";
        for(int i=0; i<26; i++){
        	if((a[i][right] - a[i][left-1])%2 == 1) {
                odd += 'a'+i;
            }
        }
        
        if(odd.size() != 1) {
        	continue;
        }
            
        int mid = left + (right - left + 1)/2;
        
        cnt = 0;
        for(int i=0; i<26; i++){
        	int n1 = a[i][mid] - a[i][left-1];
            int n2 = a[i][right] - a[i][mid];
            
            if(n1 != n2)
            	cnt++;
        }
        
        if(cnt == 1){
        	count++;
            continue;
        }
        
        cnt = 0, mid -= 1;
        for(int i=0; i<26; i++){
        	int n1 = a[i][mid] - a[i][left-1];
            int n2 = a[i][right] - a[i][mid];
            
            if(n1 != n2)
            	cnt++;
        }
        
        if(cnt == 1){
        	count++;
            continue;
        }
    }
    cout << count << "\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE 
        freopen("perfectly_balanced_chapter_1_input.txt", "r", stdin);
        freopen("perfectly_balanced_chapter_1_output.txt", "w", stdout);
    #endif
    SPEED1;

    int t, num = 1;
    cin >> t;

    while(num <= t)
        cout << "Case #" << num << ": ", solve(), num++;

    return 0;
}


