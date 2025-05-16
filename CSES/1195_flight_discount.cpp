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
#define MAX 1000000000000000
#define inpt(x) int x{}; cin >> x
using namespace std;

void solve() {
    inpt(n); inpt(m);
    vector<vector<pair<int, int>>> routes(n+1);
    For(i, 0, m) {
        inpt(x); inpt(y); inpt(z);
        routes[x].push_back({y, z});
    }
    vector<vector<int>> min_cost(n+1, {MAX, MAX});
    min_cost[1] = {0, 0};

    struct pos {
        int city;
        bool couponUsed;
        int cost;
    };
    
    auto cmp = [&](const pos& a, const pos& b) {return (a.cost > b.cost);};

    priority_queue<pos, vector<pos>, decltype(cmp)> pq(cmp);
    pq.push({1, 0, 0});
    while(!pq.empty()) {
        pos curr = pq.top();
        pq.pop();
        if(curr.cost > min_cost[curr.city][curr.couponUsed]) {
            continue;
        }
        for(auto dest: routes[curr.city]){
            if(!curr.couponUsed) {
                if(curr.cost + dest.second/2 < min_cost[dest.first][1]) {
                    min_cost[dest.first][1] = curr.cost + dest.second/2;
                    pq.push({dest.first, 1, min_cost[dest.first][1]});
                }
            }
            if(curr.cost + dest.second < min_cost[dest.first][curr.couponUsed]) {
                min_cost[dest.first][curr.couponUsed] = curr.cost + dest.second;
                pq.push({dest.first, curr.couponUsed, min_cost[dest.first][curr.couponUsed]});
            }
        }
    }

    pl(min_cost[n][1]);
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