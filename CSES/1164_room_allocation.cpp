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

bool cmp(const pair<int, pair<int,int>> &a, const pair<int, pair<int,int>> &b) {
    if(a.second.first != b.second.first) {
        return (a.second.first < b.second.first);
    } 
    else {
         if(a.first != b.first) {
        return (a.first < b.first);
    }else {
            return (a.second.second < b.second.second);
        }
    }
}

void solve() {
    inpt(n);
    vector<pair<int, pi>> arr;
    For(i, 0, n) {
        inpt(x); inpt(y);
        arr.push_back({y, {x, i}});
    }
    sort(arr.begin(), arr.end(), cmp);
    // for(auto &x: arr) {
    //     cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    // }
    // cout << endl;

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    vector<int> ans(n, 0);
    For(i, 0, n) {
        if(!pq.empty()) {
            auto temp = pq.top();
            if(temp.first < arr[i].second.first) {
                pq.pop();
                ans[arr[i].second.second] = temp.second;
                pq.push({arr[i].first, temp.second});
                // pv(ans);
                continue;
            }
        }
        ans[arr[i].second.second] = pq.size()+1;
        pq.push({arr[i].first,pq.size()+1});
        // pv(ans);
    }
    pl(pq.size());
    pv(ans);
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