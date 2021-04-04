/*
A Right rotation operation on an array of size n , shifts each of the array's elements 1 unit to the Right. For example, if 2 Right rotations are performed on array [1,2,3,4,5] then the array would become [4,5,1,2,3]. Given an array of n integers and a number d , perform d Right rotations on the array. Then print the updated array as a single line of space-separated integers.
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
#define int long long
#define END cout<<"\n"
using namespace std;

int32_t main() {
    SPEED;
    int t{0};
    cin>>t;
    For(i, 0, t){
        int n{0}, d{0};
        cin>>n;
        cin>>d;
        vi v;
        
        For(j, 0, n){
            int p{0};
            cin>>p;
            v.pb(p);
        }

        vi vtail(d);
        vi vnew(n+d);
        For(j, 0, d){
            vtail[j] = v[n-d+j];
        }
        For(j, 0, n){
            vnew[j+d] = v[j];
        }

        // for(auto &k:vtail)
        //     cout<<k<<"  ";
        // END;

        For(j, 0, d){
            vnew[j] = vtail[j];
        }

        For(j, 0, n){
            cout<<vnew[j]<<" ";
        }
        END;
    }
}