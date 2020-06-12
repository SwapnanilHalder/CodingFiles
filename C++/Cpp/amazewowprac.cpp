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

void colony(vi &cell, int n){
    For(k, 0, n){
        vi temp(cell);
        For(i, 0, 8){
            if(i == 0){
                if(cell[1] == 0){
                    temp[0] = 0;
                }
                else 
                    temp[0] = 1;
            }
            if(i == 7){
                if(cell[6] == 0){
                    temp[7] = 0;
                }
                else 
                    temp[7] = 1;
            }
            else {
                if(cell[i-1] == cell[i+1]){
                    temp[i] = 0;
                } else {
                    temp[i] = 1;
                }
            }
        }
        cell = temp;   
    }
}

int32_t main() {
    SPEED;
    vi cell(8);
    For(i, 0, 8){
        int j{0};
        cin>>j;
        cell[i] = j;
    }
    int n{0};
    cin>>n;
    vi ans(8);
    colony(cell, n);
    for(auto &i:cell){
        cout<<i<<" ";
    }
    END;
}