#include <bits/stdc++.h>
#define For(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define pmint(v) cout<< #v<<endl;for(auto itr = v.begin(); itr != v.end(); itr++){cout << "\t" << itr->first << " ->  " << itr->second;cout << "\n";}
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t'<<#x << " = " << x << endl



using namespace std;

void sol() {
    int n; cin >> n;
    vi arr(n, 0);
    For(i, 0, n) {
        cin >> arr[i];
    }
    map<int, int> mapped;
    int start=0, idx = 0, len = 0;
    For(i, 0, n) {
        if(mapped.find(arr[i]) == mapped.end()) {
            mapped[arr[i]] = i;
        }
        else {
            start = (mapped[arr[i]] >=start) ?   mapped[arr[i]]+1 : start;
            mapped[arr[i]] = i;
        }
        len = max(len, i-start+1);
        // deb(len); deb(start); deb(i);
    }
    // pmint(mapped);
    pl(len);

}

int main() {
    int t; cin >> t;
    while(t--) {
        sol();
    }
}

/*
3
5
1 2 2 1 2
4
3 3 3 3
5
1 3 2 4 1
*/

