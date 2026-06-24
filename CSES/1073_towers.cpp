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

void solve() {
    inpt(n);
    vector<int> arr;
    int count=0;
    For(i, 0, n) {
        inpt(x);
        auto it = upper_bound(arr.begin(), arr.end(), x);
        if(it == arr.end()) {
            arr.push_back(x);
            count++;
        } else {
            *it = x;
        }
    }
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



class Solution {
  public:
  class Compare {
   public:
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
      if (a.second == b.second){
          return (a.first > b.first);
      }
      return (a.second > b.second);
    }
  };
  
  bool cmp(const int &a, const int &b) {
      return (a>b);
  }
  
 
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int max_deadline = *max_element(deadline.begin(), deadline.end());

        vector<vector<int>> store(max_deadline+1);
        for(int i=0; i<deadline.size(); i++) {
            store[deadline[i]].push_back(profit[i]);
        }
        for(int i=0; i<store.size(); i++) {
            sort(store[i].begin(), store[i].end(), cmp);
        }
        
        // <day, profit>
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;  
                vector<int> dp(max_deadline+1, 0);

        for(int i=1; i<=max_deadline; i++) {
            pq.push({i, 0});
            for(int j=0; j<store[i].size(); j++) {
                auto temp = pq.top();
                if(temp.second >= store[i][j]) {
                    break;
                }
                pq.pop();
                temp.second = store[i][j];
                pq.push(temp);
            }
        }
        int count_days = 0, total_profit = 0;
        
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if(temp.second != 0)  {
                count_days++;
                total_profit += temp.second;
            }
        }

        
        
        // pair<int, int> <deadline, max_profit>
        
        // int max_deadline = *max_element(deadline.begin(), deadline.end());
        
        // map<int, priority_queue<int>> mp;
        // for(int i=0; i<deadline.size(); i++) {
        //     mp[deadline[i]].push(profit[i]);
        // }
        // vector<int> dp(max_deadline+1, 0);
        // for(int i=1; i<= max_deadline; i++) {
        //     int j=i;
        //     while(j >= 1 && !mp[i].empty()) {
        //         int tempMax = mp[i].top();
        //         // cout << "for i, j: " << i <<","<<j<<" tempMax: " << tempMax << endl; 
        //         mp[i].pop();
        //         dp[j] = max(dp[j], tempMax);
        //         j--;
        //     }
        // }
        // int count_days = 0, total_profit = 0;
        // for(int i=1; i<= max_deadline; i++) {
        //     if(dp[i] != 0) {
        //         count_days++;
        //         total_profit += dp[i];
        //     }
        // }
        return vector<int>{count_days, total_profit};
        
    }
};