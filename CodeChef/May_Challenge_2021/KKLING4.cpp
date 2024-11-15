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
#define long_long long long
#define mod 1000000007/

using namespace std;
vector<long_long> array_ans[200008],value,childs,ans; 

void dfs(long_long now, long_long last){ 

for(long_long i=0; i<array_ans[now].size(); i++){ 
    
        long_long abcdef= array_ans[now][i]; 
        if(abcdef!=last) 
        dfs(abcdef,now); 
    }
    childs.clear();
    
    for(long_long i=0; i<array_ans[now].size(); i++){  
        
        long_long abcdef= array_ans[now][i];  
        if(abcdef!=last)
        childs.pb(value[abcdef]); 
    }
    if(childs.size()>0){
        sort(childs.begin(),childs.end()); 
        
        long_long x=childs[0];
        long_long checker=0; 
        
        for(long_long i=0; i<childs.size(); i++){  
            if(childs[i]!= x) checker++;  
            
        }
        if(checker==0)  value[now]+= x+1; 
        
        if(checker!=0) value[now]+= x +2;      
    }
    else
    value[now]=0; 
}
 

void dfs1(long_long node, long_long par, long_long minimumm){
  
    for(long_long i=0; i<array_ans[node].size(); i++){  
        
        long_long abcdef= array_ans[node][i];
        minimumm = min(minimumm,value[node]);
        if(abcdef!=par){
            if(value[abcdef]>=minimumm-1){
            dfs1(abcdef,node,minimumm);
            }
        }
    }
    if(value[node]==0){
        ans.pb(node);
    }
}    
    



int32_t main(){
    SPEED1;
    long_long t = 1; cin >> t;
    while(t--) {
        long_long N; cin >> N;

        value.assign(N+1,0);

        for(long_long i=0;i<N-1; i++)
        {
            int l, r;
            cin >> l >> r;
            array_ans[l].pb(r), array_ans[r].pb(l);
        }

        dfs(1,0);


        int minx = INT_MAX;
        
        for(long_long i = 0; i<array_ans[1].size(); i++){
            long_long abcdef = array_ans[1][i];
            if(value[abcdef]<minx){
                minx = value[abcdef];
            }
        }

        for(long_long i=0; i<array_ans[1].size(); i++){
            
            long_long abcdef = array_ans[1][i];
            if(value[abcdef] == minx)
            
            dfs1(abcdef,1,minx);

        }

        sort(all(ans));
        
        cout<<ans.size()<<" "<<minx+1<<endl;
        
        pv(ans);
        

        for (long_long i = 1; i <=N; ++i) {array_ans[i].clear(); }
        value.clear();
        ans.clear();  
       

    } 
    
    return 0;
    
}