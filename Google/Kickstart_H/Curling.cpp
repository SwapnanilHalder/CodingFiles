#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[2] < v2[2];
}

void solve() {
    int rs, rh; cin>>rs>>rh;
    int m; cin>>m;
    if(m == 0) {
        int n; cin >> n;
        vector<vector<int> > v2(n, vector<int>(3));

        For(i, 0, n) {
            cin >> v2[i][0] >> v2[i][1];
            v2[i][2] = (v2[i][0] * v2[i][0]) + (v2[i][1] * v2[i][1]);
        }
        sort(v2.begin(), v2.end(), sortcol);
        int total = 0, idx=0;
        while(idx <n && v2[idx][2] <= rs*rs + rh*rh + 2*rs*rh ) {
            total++;
            idx++;
        }
        cout << "0" <<  " " << total << endl;
        return;
    }
    vector<vector<int> > v1(m, vector<int>(3));
    For(i, 0, m) {
        cin >> v1[i][0] >> v1[i][1];
        v1[i][2] = (v1[i][0] * v1[i][0]) + (v1[i][1] * v1[i][1]);
    }
    sort(v1.begin(), v1.end(), sortcol);
    
    int n; cin >> n;
    if(n == 0) {
        int total = 0, idx=0;
        while(idx < m && v1[idx][2] <= rs*rs + rh*rh + 2*rs*rh ) {
            total++;
            idx++;
        }
        cout << total <<  " " << "0" << endl;
        return;
    }
    vector<vector<int> > v2(n, vector<int>(3));

    For(i, 0, n) {
        cin >> v2[i][0] >> v2[i][1];
        v2[i][2] = (v2[i][0] * v2[i][0]) + (v2[i][1] * v2[i][1]);
    }
    sort(v2.begin(), v2.end(), sortcol);

    if(v2[0][2] > v1[0][2]) {
        int total = 0, idx=0;
        while(idx < m && v1[idx][2] < v2[0][2] && v1[idx][2] <= rs*rs + rh*rh + 2*rs*rh ) {
            total++;
            idx++;
        }
        cout << total <<  " " << "0" << endl;

    }
    else {
        int total = 0, idx=0;
        while(idx < n && v2[idx][2] < v1[0][2] && v2[idx][2] <= rs*rs + rh*rh + 2*rs*rh) {
            total++;
            idx++;
        }
        cout << "0" <<  " " << total << endl;        
    }

}


int32_t main(){
    SPEED1;;

    int t, x = 1;
    cin >> t;

    while(x <= t){
        cout << "Case #" << x << ": ";
        solve();
        x++;
    }

    return 0;
}