#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;



int target; 
vi group;
vi bucket;

bool put(int n) {
    for( int i = 0; i < bucket.size(); ++i ) {
        if( bucket[i] + group[n] > target ) continue; 
        bucket[i] += group[n]; 
        if( n == group.size() - 1 ) return true; 
        if( put( n + 1 ) ) return true; 
        else { 
            bucket[i] -= group[n]; 
            if( bucket[i] == 0 ) {
                return 0;
            }
        }
    }
    return false; // no bucket fits
}

bool answer( vector<int>& nums, int k ) {
    int sum = 0;
    for( int &n : nums ) sum += n;
    if( sum % k ) return false; 
    target = sum / k;
    group = vi( nums );
    bucket = vi( k, 0 );
    sort( all(group) );
    reverse( all(group) );
    return put( 0 );
}

void sol() {
    int n; cin >> n;
    vi arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k; cin >> k;
    cout << answer(arr, k) << endl;

}

int32_t main() {
    sol();
}

