#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> a(3),b(3), c(2,0);
    for (auto &i:a){
        cin>>i;
    }
    for (auto &i:b){
        cin>>i;
    }
    for (int i{0}; i<3; i++){
        if (a[i]>b[i]){
            c[0]++;
        } else if(b[i]>a[i]){
            c[1]++;
        }
    }
    for (auto &i:c){
        cout<<i<<' ';
    }
}
