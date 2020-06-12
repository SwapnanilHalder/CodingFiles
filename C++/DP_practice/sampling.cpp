#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926536
#define MAX 1000005
//#define int long long
#define END cout<<"\n"
using namespace std;

vi v(8,-1);

int sampling(int n){
    if (n < 0){
        return 0;
    }
    if((n == 1) || (n == 0)){
        return 1;
    }
    if(v[n] != -1){
        return v[n];
    }

    return v[n] = sampling(n-5) + sampling(n-3) + sampling(n-1); 
}


int32_t main() 
{ 
    vi val = {1,3,5};
    int n = 7;
    int l = sizeof(val) / sizeof(val[0]);
    for(auto &i:v){
        cout<<i<< "  ";
    }END;

    int ans = sampling(n);

    for(auto &i:v){
        cout<<i<<" ";
    }END;

    cout<<ans<<endl;
}