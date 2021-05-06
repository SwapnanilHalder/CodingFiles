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
#include <queue>
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define lolo long long
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

lolo not_tt(lolo x){
    if(x==0)
        return 1;
    lolo k=x,ct=0;
    while(k){
        k/=2;
        ct++;
    }
    if(1<<(ct-1)==x)
        return x-1;
    return (1<<(ct))-x-1;
}
int32_t main()
{
    SPEED;
    lolo t_e_st;
    cin>>t_e_st;
    for(lolo t_t=1;t_t<=t_e_st;t_t++){
    map<lolo,lolo> m;
    string s,t;
    cin >> s;
    cin >> t;
    lolo v1=0,v2=0;
    for(auto it:s){
        v1*=2;
        v1+=it-'0';
    }
    for(auto it:t){
        v2*=2;
        v2+=it-'0';
    }
    if(v1==v2){
        cout<<"Case #"<<t_t<<": 0"<<endl;
        continue;
    }
    queue<pair<lolo,lolo>> q;
    q.push({v1,0});
    while(!q.empty()){
        pair<lolo,lolo> y=q.front();
        q.pop();
        if(m[y.first]!=0ll && m[y.first]<y.second)
            continue;
        if(y.first>(1<<16))
            continue;
        if(m[v2]!=0 && m[v2]<y.second)
            continue;
        m[y.first]=y.second;
        q.push({y.first*2,y.second+1});
        q.push({not_tt(y.first),y.second+1});
    }
    if(m[v2]!=0)
        cout<<"Case #"<<t_t<<": "<<m[v2]<<endl;
    else
        cout<<"Case #"<<t_t<<": IMPOSSIBLE"<<endl;
    }
    return 0;
}