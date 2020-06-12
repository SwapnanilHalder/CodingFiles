/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
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

int32_t palindrome(int A) {
    string str = to_string(A);
    //cout<<str;END;
    int len = str.length();
    //cout<<len;END;

    int j = 0;
    while(j < len/2) {
        if(str[j] != str[len-1-j]) {
            break;
        }
        j++;
    }
    if(j == len/2)
        return 1;
    else 
        return -1;
}

int32_t main()
{
    int mul{0};
    vi v;
    For(i, 100, 1000) {
        For(j, 100, 1000) {
            mul = i * j;
            if(palindrome(mul) > 0) {
                v.pb(mul);
            }
        }
    }
    cout << "\n Max Palindrome : "<<*max_element(v.begin(), v.end());END;
    // for(auto i:v) {
    //     cout<<i;END;
    // }
}