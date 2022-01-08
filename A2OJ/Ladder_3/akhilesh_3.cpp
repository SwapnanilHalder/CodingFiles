#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a, vector<int> b, int k){
    int n = a.size();
    vector<pair<int,int>> v(n), v2;
    vector<int> v3;
    for(int i=0;i<n;i++){
        v[i] = {a[i], b[i]};
    }
    sort(v.begin(), v.end());

    for(int i=0;i<n;i++){
        int s = v[i].first, e = v[i].second;
        int j = i+1;
        // cout <<"i:" << i <<"\n";
        while(j<n && v[j].first<= e ){
            // cout <<"j:" << j <<" ";
            e = max(e, v[j].second);
            // cout <<"e:" << e <<"\n";
            j++;
        }
        // cout <<"\n";
        v2.push_back({s,e});
        v3.push_back(s);
        if(i==n-1) break;
        i=j-1;
    }

    // cout << "v2: ";
    // for(auto x : v2) cout << x.first <<" " << x.second << "\n";

    int ans = v2.size(), m = v2.size();

    for(int i = 0 ; i < m ;i++){
        int temp = i;
        int x = v2[i].second + k;
        int how = m - (upper_bound(v3.begin(), v3.end(), x) - v3.begin() )  ;

        temp += how +1;

        ans = min(ans, temp);
    }

    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];

    cout << solve(a,b,k);
}