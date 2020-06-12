/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define fill(a) memset(a,0,sizeof(a))
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926536
#define MAX 1000005
#define int long long
#define END cout<<"\n"
using namespace std;

int32_t main() {
    int num = 600851475143;
    int num1 = num;
    vi v;
    int sq = (int)sqrt(num);
    For(i, 2, sq+1) {
        if(num1 % i == 0) {
            v.push_back(i);
            num1 /= i;
            cout<<num1<<endl;
        }
    }
    cout << endl<<sq << endl;
    for(auto i:v) {
        cout<< " " << i;
    }
    END;
}