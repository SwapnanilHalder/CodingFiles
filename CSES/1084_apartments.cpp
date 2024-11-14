#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> apartment(n), choice(m);
    For(i, 0, n) {
        cin >> apartment[i];
    }
    For(i, 0, m) {
        cin >> choice[i];
    }
    sort(apartment.begin(), apartment.end());
    sort(choice.begin(), choice.end());

    int count = 0;

    int apartment_idx = 0, choice_idx = 0;
    while(choice_idx < m && apartment_idx < n) {
        if(apartment[apartment_idx] < choice[choice_idx] -k) {
            apartment_idx++;
            continue;
        }
        if(choice[choice_idx] - k <= apartment[apartment_idx] && choice[choice_idx] + k >= apartment[apartment_idx]) {
            count++;
            apartment_idx++;
            choice_idx++;
            continue;
        }

        if(choice[choice_idx] + k < apartment[apartment_idx]) {
            choice_idx++;
            continue;
        }
    }
    cout << count << endl;
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int __t; cin >> __t; while(__t--)
    solve();
}

// 5 6 10 45 60 60 80
// 30 60 75


// 25-35 
// i = 0 -> 45