/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
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

int main(){
    int count{4};
    int num{9};  
    while(count<10001) {
        int notprime{0};
        int sqr = (int)sqrt(num);
        For(i, 2, sqr+1){
            if(num % i == 0) {
                notprime = 1;
                //cout<<num<<"  ";
                break;
            
            }
        }
        if(notprime == 0){
            count++;
        }
        num++;
    }
    cout<<endl<<num-1;END;
}