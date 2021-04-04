#include <stdio.h>     
#include <stdlib.h>    
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
 
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
#define ld long double
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<iii,int>
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define vv vector
#define endl '\n'
 
using namespace std;
 
const int MAXN = 100*1000 + 5;
 
inline ll mulFac(ll a,ll b,ll c,ll d){
	if(b != a and (d-c)%(b-a) == 0){
		return (d-c)/(b-a);
	}else{
		return 1;
	}
}
 
inline bool equal(ll* a, ll* b){
	FOR(i,3)if(a[i] != b[i])return false;
	return true;
}
int best;
void solve(ll* a,ll* b,int num = 0){
	if(num >= best)return;
	if(equal(a,b)){
		best = min(best,num);
		return;
	}
	if(num >= 2)return;
 
	set<ll> add;
	add.insert(b[0]-a[0]);
	add.insert(b[1]-a[1]);
	add.insert(b[2]-a[2]);
	set<ll> mult;
	FOR(i,3)if(a[i] != 0 and b[i]%a[i] == 0)mult.insert(b[i]/a[i]);
	mult.insert(mulFac(a[0],a[1],b[0],b[1]));
	mult.insert(mulFac(a[2],a[1],b[2],b[1]));
	mult.insert(mulFac(a[0],a[2],b[0],b[2]));
	mult.insert(0);
	
	FORE(mask,1,7){
		vi all;
		FOR(j,3)if(mask&(1<<j))all.pb(j);
		for(auto x: add){
			ll aa[3];
			FOR(j,3)aa[j] = a[j];
			for(auto e: all)aa[e]+=x;
			solve(aa,b,num+1);
		}
		for(auto x:mult){
			ll aa[3];
			FOR(j,3)aa[j] = a[j];
			for(auto e: all)aa[e]*=x;
			solve(aa,b,num+1);
		}
 
	}
}
 
void solve(){
	best = 3;
	ll a[3];
	ll b[3];
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	solve(a,b);
	cout << best << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
} 