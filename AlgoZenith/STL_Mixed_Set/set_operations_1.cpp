#include <bits/stdc++.h>
#define vi vector<int>
#define For(i, a, b) for(int i=a; i<b; i++)
#define MAX 100000009//std::numeric_limits<int>::max()
#define pv(v) for(const auto &i: v){cout<<i<<" ";}cout << "\n"
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define pb push_back


using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    // int MAX = n+m;
    vector<int> a(n, 0), b(m, 0);
    int t;
    For(i, 0, n) {
        cin >> a[i];
    }
    For(i, 0, m) {
        cin >> b[i];
    }
    sort(all(a)); sort(all(b));
    int i1=0, i2=0;
    vi unio, inters, sub;
    // a[i1] should always be less than b[i2]
    while(i1 < n && i2 < m) {
        if(a[i1] == b[i2]) {
            unio.pb(a[i1]);
            inters.pb(a[i1]);
            i1++; i2++; continue;
        }
        if(a[i1] > b[i2]) {
            unio.pb(b[i2]);
            i2++; continue;
        }
        else {
            unio.pb(a[i1]);
            sub.pb(a[i1]);
            i1++; continue;
        }
    }
    if(i1 == n) {
        for(;i2 < m; i2++) {
            unio.pb(b[i2]);
        }
    }
    if(i2 == m) {
        for(;i1<n; i1++) {
            unio.pb(a[i1]);
            sub.pb(a[i1]);
        }
    }
    pv(unio); pv(inters); pv(sub);

    // For(i, 0, MAX) {

    //     if(a[i]){
    //         unio.push_back(i);
    //         if(b[i]) {
    //             inters.push_back(i);
    //         } 
    //         else {
    //             sub.push_back(i);
    //         }
    //     }
    //     else if(b[i]) {
    //         unio.push_back(i);
    //     }
    // }

}

int main() {
    SPEED1;
    int t; cin >> t;
    while(t--) {
        sol();
    }
}

/*
3
4 5
2 4 1 5
4 5 6 9 3
2 3
4 5
6 7 1
3 3
1 2 3
1 2 3
*/
