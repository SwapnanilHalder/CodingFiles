#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define For(i, a, b) for(int i=a; i<b; i++)

using namespace std;

void sol() {
    set<int> sett;
    int n; cin >> n;
    int x;
    For(i, 0, n) {
        cin >> x;
        sett.insert(x);
    }
    cout << sett.size() << endl;
}


int main() {
    SPEED1;
    int t; cin >> t;
    while(t--) {
        sol();
    }
}