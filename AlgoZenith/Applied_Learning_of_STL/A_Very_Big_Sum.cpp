#include <bits/stdc++.h>
using namespace std;
#define MOD 10000007
#define ll long long int

class Solution {
public:
    ll check(ll &x) {
        if(x > MOD) {
            x %= MOD;
        }
        return x;
    } 
    int numFactoredBinaryTrees(vector<int>& arr) {
        vector<ll> arr1(arr1);
        int n= arr1.size();
        ll count = 0;
        sort(arr1.begin(), arr1.end());
        map<int, ll> mapp;
        for(int i=0; i<n; i++) {
            mapp[arr1[i]] = 1;
            for(int j=i-1; j>=0; j--) {
                if((arr1[i] % arr1[j])==0 && binary_search(arr1.begin(), arr1.begin()+j+1, (arr1[i]/arr1[j]))) {
                    // cout << "pair got for :" << arr1[i] << " , " << arr1[j] << ", " << arr1[i]/arr1[j] << endl;
                    if(arr1[i] / arr1[j] == arr1[j]) {
                        mapp[arr1[i]] += ((ll)mapp[arr1[j]]*(ll)mapp[arr1[j]]) ;
                        // check(mapp[arr1[i]]);
                    }
                    else {
                        mapp[arr1[i]] += (( 2*(ll)mapp[arr1[j]]*(ll)mapp[(arr1[i]/arr1[j])] ));
                        // check(mapp[arr1[i]]);
                    }
                } 
            }
        }
        for(auto &x: mapp) {
            cout << x.first << " : " << x.second << endl;
            count += (x.second % 10000007);
            count %= 10000007;
            // check(count);
        }
        return count;
    }
};