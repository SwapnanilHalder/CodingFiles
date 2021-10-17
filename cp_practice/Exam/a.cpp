#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n, 0);
    int is_even = 0;
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
        if( (arr1[i] & 1 ) == 0) {
            is_even = 1;
        }
    }
    int m;
    cin >> m;
    vector<int> arr2(m, 0);
    for(int i=0; i<m; i++) {
        cin >> arr2[i];
        if( (arr2[i] & 1 ) == 0) {
            is_even = 1;
        }
    }
    int sum1 = accumulate(all(arr1), 0);
    int sum2 = accumulate(all(arr2), 0);
    if( (sum1+sum2) & 1) {
        cout << "-1\n";
        return 0;
    }    
    if( (sum1 & 1 ) == 0) {
        cout << "0\n";
        return 0;
    }
    if(is_even == 0) {
        cout << "-1\n";
        return 0;     
    }
    cout << "1\n";
    return 0;
}