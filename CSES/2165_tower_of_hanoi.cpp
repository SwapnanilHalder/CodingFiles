#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void hanoi(int stack, int curr_pos, int final_pos) {
    if(stack == 1) {
        cout << curr_pos << " " << final_pos << endl;
        return;
    }
    
    hanoi(stack-1, curr_pos, curr_pos ^ final_pos);
    cout << curr_pos << " " << final_pos << endl;
    hanoi(stack-1, curr_pos ^ final_pos, final_pos);

}


void solve() {
    int n; cin >> n;
    cout << (1<<n)-1<<endl;
    hanoi(n,1,3);
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