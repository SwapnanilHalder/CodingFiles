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
#define long_long long long
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
#define timestart auto start = chrono::high_resolution_clock::recent()
#define timestop auto stop = chrono::high_resolution_clock::recent();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}


using namespace std;
vector<long_long> array_ans[200008],value,children,ans; 

void dfs(long_long recent, long_long enddd){ 

    For(i, 0, array_ans[recent].size() ) { 
        long_long child= array_ans[recent][i]; 
        if(child!=enddd) {
            dfs(child,recent);
        }
         
    }
    children.clear();
    
    For(i, 0, array_ans[recent].size() ){  
        long_long child= array_ans[recent][i];  
        if(child!=enddd)
        children.pb(value[child]); 
    }
    if(children.size()>0){
        sort(all(children)); 
        
        long_long x=children[0];  
        long_long checkedd=0; 
        
        for(long_long i=0; i<children.size(); i++){  
            if(children[i]!= x) {
                checkedd++;
            } 
        }
        if(checkedd==0) value[recent]+= x+1; 
        
        if(checkedd!=0) value[recent]+= x +2;      
    }
    else {
        value[recent]=0;
    }
    
}
 

void dfs1(long_long node, long_long par, long_long minimumm){
  
    For(i, 0, array_ans[node].size() ){  
        
        long_long child= array_ans[node][i];
        minimumm = min(minimumm,value[node]);
        if(child!=par){
            if(value[child]>=minimumm-1){
            dfs1(child,node,minimumm);
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

        
        For(i, 0, N-1)
        {
            inpt(l); inpt(r);
            array_ans[l].pb(r), array_ans[r].pb(l);
        }

        dfs(1,0);


        int another_value = INT_MAX;
        
        
        For(i, 0, array_ans[1].size() ) {
            long_long child = array_ans[1][i];
            if(value[child]<another_value){
                another_value = value[child];
            }
        }

        For(i, 0, array_ans[1].size() ){
            
            long_long child = array_ans[1][i];
            if(value[child] == another_value) {
                dfs1(child,1,another_value);
            }
            

        }

        sort(all(ans));
        
        cout<<ans.size()<<" "<<another_value+1<<endl;
        
        pv(ans);
    } 
    
    return 0;
    
}