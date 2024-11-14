#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void backtrack(int idx, string str, vector<int> arr, int len, vector<string> &ans) {
    // cout << "Entered backtrack : " << str  << " ; idx: " << idx << endl;
    if(idx == len) {
        ans.push_back(str);
        return;
    }
    For(i, 0, 26) {
        if(arr[i] > 0) {
            arr[i]--;
            backtrack(idx+1, str + static_cast<char>('a'+i), arr, len, ans);
            arr[i]++;
        }
    }
}

void solve() {
    string s; cin >> s;
    vector<int>arr(26);
    vector<string> ans;

    For(i, 0, s.size()) {
        arr[s[i] - 'a']++;
    }
    string str="";
    For(i, 0, 26) {
        // cout << i << " : " << arr[i] << endl;
        if(arr[i] > 0) {
            arr[i]--;
            char c = static_cast<char>('a' + i);
            string a(1, c);
            backtrack(1, a, arr, s.size(), ans);
            arr[i]++;
        }
    }
    cout << ans.size() << endl;
    For(i, 0, ans.size()) {
        cout << ans[i] << endl;
    }
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