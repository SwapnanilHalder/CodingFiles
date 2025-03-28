#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int k, n; cin>>k>>n;

    map<int, int> mp; multiset<int> st;

    mp.insert({0,k}); st.insert(k);
    int x;
    For(i, 0, n) {
        cin >> x;
        
        auto it = mp.lower_bound(x);
        it--;

        int prev = it->second;
        st.erase(st.find(prev));
        int first = x - it->first ;
        it->second = first;
        st.insert(first);
        int second = prev - first;
        mp.insert({x, second});
        st.insert(second);
        cout << *st.rbegin() << " ";
    } 
    return;
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




