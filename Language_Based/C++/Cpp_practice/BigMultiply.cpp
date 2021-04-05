#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
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
#define lli long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << #x << "=" << x << endl
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, a) for(const auto &it = a.begin(); it != a.end(); it++)
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
using namespace std;

void product(string a, string b)
{
    vector<int> result(a.size() + b.size(), 0);
    for (int i = a.size() - 1; i >= 0; i--)
    {
        for (int j = b.size() - 1; j >= 0; j--)
        {
            result[i + j + 1] += (b[j] - '0') * (a[i] - '0'); //single array to store intermediate values
        }
    }
    for (int i = a.size() + b.size(); i >= 0; i--)
    {
        if (result[i] >= 10)
        {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    //cout << a << " * " << b << " = ";
    for (int i = 0; i < a.size() + b.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;
}
int main(void)
{
    timestart;
    string num1, num2;
    //cin >> num1;cin >> num2;
    num1 = "99900000000000000000999999999999999999", num2 = "9999999999999999999999999999999999999999999999999";
    product(num1, num2);
    timestop;
    return 0;
}