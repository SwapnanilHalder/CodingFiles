#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    int n, q; cin >>n>>q;
    string s; vector<int> arr(n);
    // getline(cin, s);
    // getline(cin, s);
    // stringstream X(s);
    // while(getline(X, s, ' ')) {
    //     arr.push_back(stoll(s));
    // }
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int t, x, k; vector<int>::iterator a = arr.begin();vector<int>::iterator it;
    for(int i=0; i<q; i++) {
        cin >>t>>x;
        switch(t) {
            case 1:
                it = lower_bound(arr.begin(), arr.end(), x);
                cout << ((it != arr.end()) ? *it : -1) << " ";
                break;
            case 2:
                it = upper_bound(arr.begin(), arr.end(), x);
                cout << ((it != arr.end()) ? *it : -1) << " ";
                break;                
             case 3:
                it = upper_bound(arr.begin(), arr.end(), x);
                cout << (it-arr.begin()) << " ";
                break;
            case 4:
                it = lower_bound(arr.begin(), arr.end(), x);
                cout << (it-arr.begin()) << " ";
                break;    
            // case 1:
            //     k = lower_bound(arr.begin(), arr.end(), x) - a;
            //     cout << ((k == n) ? -1 : arr[k]) << " ";
            //     break;
            // case 2:
            //     k = upper_bound(arr.begin(), arr.end(), x) - a;
            //     cout << ((k == n) ? -1 : arr[k]) << " ";
            //     break;
            // case 3:
            //     k = upper_bound(arr.begin(), arr.end(), x) - a;
            //     cout << k << " ";
            //     break;
            // case 4:
            //     k = lower_bound(arr.begin(), arr.end(), x) - a;
            //     cout << k << " ";
            //     break;
        }
    }
    cout << endl;
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int __t; cin >> __t; while(__t--)
    solve();
}



// #include <bits/stdc++.h>
// #define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
// using namespace std;

// void solve() {
//     int n, q; cin >>n>>q;
//     string s; vector<int> arr;
//     getline(cin, s);
//     getline(cin, s);
//     stringstream X(s);
//     while(getline(X, s, ' ')) {
//         arr.push_back(stoll(s));
//     }
//     sort(arr.begin(), arr.end());
//     int t, x; vector<int>::iterator it;
//     for(int i=0; i<q; i++) {
//         cin >>t>>x;
//         switch(t) {
//             case 1:
//                 it = lower_bound(arr.begin(), arr.end(), x);
//                 cout << ((it != arr.end()) ? *it : -1) << " ";
//                 break;
//             case 2:
//                 it = upper_bound(arr.begin(), arr.end(), x);
//                 cout << ((it != arr.end()) ? *it : -1) << " ";
//                 break;                
//              case 3:
//                 it = upper_bound(arr.begin(), arr.end(), x);
//                 cout << (it-arr.begin()) << " ";
//                 break;
//             case 4:
//                 it = lower_bound(arr.begin(), arr.end(), x);
//                 cout << (it-arr.begin()) << " ";
//                 break;                
//         }
//     }
//     cout << endl;
// }

// signed main() {
//     SPEED1;
//     #ifndef ONLINE_JUDGE 
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     int __t; cin >> __t; while(__t--)
//     solve();
// }
