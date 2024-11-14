#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
// #define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

// void generateAllBinaryStrings(vector<int> &arr, int n, int curr_idx) {
//     // cout << "Entered generateAllBinaryStrings : Curr_idx :" << curr_idx << endl; 
//     if(curr_idx == n) {
//         For(i, 0, n) {
//             cout << arr[i];
//         } cout << endl;
//         return;
//     }
//     vector<int> arr1 = arr, arr2 = arr;
//     arr1[curr_idx] = 0;
//     arr2[curr_idx] = 1;
//     generateAllBinaryStrings(arr1, n, curr_idx+1);
//     generateAllBinaryStrings(arr2, n, curr_idx+1);
// }

string toBinaryString(int number, int bits) { 
    std::string result = ""; 
    for (unsigned int i = 0; i < bits; ++i) { 
        result = ((number & (1 << i)) ? "1" : "0") + result;
    } 
    return result;
}

void solve() {
    int n; cin >> n;
    vector<int> arr{0, 1};
    For(i, 1, n) {
        for(int j = (1<<i)-1; j>=0; j--) {
            arr.push_back(arr[j]+(1<<i));
        }
    }
    int k = n;
    For(i, 0, arr.size()) {
        cout << toBinaryString(arr[i], k) << endl;
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