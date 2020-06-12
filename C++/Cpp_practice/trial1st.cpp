#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define fill(a) memset(a,0,sizeof(a))
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926536
#define MAX 1000005
#define int long long

using namespace std;
 int32_t main(){
     int n = 10;
     int incr = 0;
     For(i,0,10){
        incr+=9*pow(10,i)*(9-i);
     }
     int x{0};
     cin>>x;
     int actual_pos = x+incr;
     int actual_no=(actual_pos + 9)/10;
     int t = actual_pos / 10;
     if(t==0){
        cout<<actual_no%10;
     }
 }
