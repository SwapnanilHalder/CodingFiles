#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;

#define SIZE 32

class Trie {
public:
    int val = 0;
    Trie* arr[2]; 
};


void insert(Trie* t, int val) {
    Trie* head = t;
    for(int i=SIZE-1; i>=0; i--) {
        bool ok = val & (1 << i);
        if(head->arr[ok] == NULL) {
            head->arr[ok] = new Trie();
        } 
        head = head->arr[ok];
    }
    // cout << "Insertion DOne\n";
    head->val = val;
}

int query(Trie* t, int val) {
    // cout << "Query for: " << val << endl;
    Trie* head = t;
    for(int i=SIZE-1; i>=0; i--) {
        bool ok = (val & (1 << i));
        // cout << " At i: " << i << endl;
        if(head->arr[1 - ok] != NULL) {
            // cout << "Got reverse\n";
            head = head->arr[1 - ok];
        } else if(head->arr[ok] != NULL) {
            // cout << "No Reverse, same\n";
            head = head->arr[ok];
        } 
        // else {
        //     break;
        // }
    }
    // cout << "Returning: " << (val ^ head->val) << endl;
    return val ^ head->val;
}


void solve() {
    inpt(n);

    int ans = INT_MIN;
    int prev_xor = 0;
    Trie* t = new Trie();
    insert(t, 0);

    For(i, 0, n) {
        inpt(x);
        prev_xor ^= x;
        insert(t, prev_xor);
        // int temp = query(t, prev_xor);
        ans = max(ans, query(t, prev_xor));
        // deb(i); deb(ans);
    }
    pl(ans);
    return;

}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //int __t; cin >> __t; while(__t--)
    solve();
}