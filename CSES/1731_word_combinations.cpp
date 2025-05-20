#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define pi pair<int,int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;

class Trie{
public:
    bool flag = 0;
    Trie* child[26];
};

string str;
int len;
Trie* original;

void insert(Trie* t, string s) {
    deb(s);
    Trie* head = t;
    for(auto &x: s) {
        cout << x << endl;
        if(head->child[x-'a'] == NULL) {
            head->child[x-'a'] = new Trie();
        }
        head = head->child[x-'a'];
    }
    head->flag = 1;
}

int findSol(string str, Trie* head, int idx) {
    // received ababc, t, 0
    deb(idx); deb(str[idx]); pl("");
    if(head == NULL) {
        pl("head is NULL");
        return 0;
    }
    if(idx == str.length()) {
        if(head->flag == 1) {
            pl("found -> returning");
            return 1;
        } else {
            pl("not found");
            return 0;
        }
    }
    int ans = 0;
    if(head->flag == 1) {
        ans += findSol(str, original, idx+1);
        cout << "Flag was on for: " << idx+1 << endl;
        deb(ans);
    }
    if(head->child[str[idx]-'a'] != NULL) ans += findSol(str, head->child[str[idx]-'a'], idx+1);
    cout << "Normal: " << idx+1 << endl;
    deb(ans);
    return ans;
}

void solve() {
    cin >> str;
    len = str.size();
    inpt(n);
    original = new Trie();
    Trie* t = original;
    cout << "76\n";
    For(i, 0, n) {
        string s;  cin >> s;
        insert(t, s);
    }

    int ans = findSol(str, t, 0);
}

signed main() {
    // SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //int __t; cin >> __t; while(__t--)
    solve();
}