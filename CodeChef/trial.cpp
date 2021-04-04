#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define ll long long
#define int long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << #x << "=" << x << endl
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, a) for(const auto &it = a.begin(); it != a.end(); it++)
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
  
bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 
  
int32_t main() { 
    ford(i, 100, 1) {
        if(i*(i+1)/2 %2 == 0) {
            int n = 2*i*i + 2*i + 1;
            int ans = (2*i+1 - sqrtl(n)) / 2;
            ans++;
            int high_sum = (i*(i+1)/2 - (i-ans)*(i-ans+1)/2) ;
            int low_sum = (i-ans)*(i-ans+1)/2 ;
            int target_diff = high_sum - i*(i+1)/4; 
            if ( ans <= target_diff)
            cout << i  << "  ans -> " << ans << "   diff: " << target_diff <<  endl; 
        }
    }
    cout<<"END" << endl;
  
  
  return 0; 
}