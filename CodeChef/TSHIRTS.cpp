#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926536
#define MOD 1000000007
#define ll long long
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
using namespace std;

vector<vi> t2p(101, vi(0));

vector<vi> person2tshirt() {
    int n{0};
    cin >> n;
    cinbuffer;
    vector<vi> p2t (n, vi(0));
    For(i, 0, n){
        string str, num;
        getline(cin, str);
        stringstream X(str);
        while(getline(X, num, ' ')){
            p2t[i].pb(stoi(num));
        }
    }
    END;
    for(const auto &v : p2t) {
        for(const auto &i: v){
            cout<< i << " ";
        }
        END;
    }

    return p2t;
}

vector<vi> tshirt2person(vector<vi> &p2t) {
    For(i, 0, p2t.size()){
        For(j, 0, p2t[i].size()) {
            t2p[p2t[i][j]].pb(i+1);
        }
    }
    END;
    for(int i=0;i<=100;i++){
        sort(t2p[i].begin(),t2p[i].end());
        if(t2p[i].size()>0){
            cout<<"T-Shirt "<<i<<" -> ";
            for(auto j:t2p[i]){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    return t2p;
}

int main() {
    int t{0};
    cin >> t;
    while(t--) {
        vector<vi> p2t = person2tshirt();
        vector<vi> t2p = tshirt2person(p2t);

        
    }

}