/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

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

int32_t main() {
    
    vector<int> v;
    cout<<"Enter the number below which we have to check: ";
    int n{0};
    cin >> n;
    For(i,0,n) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            v.pb(i);
        }
    }
    for (auto i : v)
        cout << i << " ";

    cout << "\nSum = " << accumulate(v.begin(), v.end(), 0)<< endl; 
    return 0;
}