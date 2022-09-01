#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    int n; cin>>n; string s; int x; vector<int> arr;
    for(int i=0;i <n; i++) {
        cin >> s;
        if(s == "add") {
            cin >> x;
            arr.push_back(x);
        }
        if(s == "print") {
            cin >> x;
            if(x >= arr.size()) {
                cout << "0" << endl;
            }
            else 
                cout << arr[x] << endl;
        }
        if( s == "remove") {
            arr.erase(arr.begin()+arr.size()-1);
        }
        if(s == "clear") {
            arr.clear();
        }
    }
    return;
}

signed main() {
    SPEED1;
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int __t; cin >> __t; while(__t--)
    solve();
}