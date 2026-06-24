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
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> grid(n, vector<int>(m));
    long long total_ones = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            total_ones += grid[i][j];
        }
    }

    long long target = total_ones / 2;
    long long current_ones = 0;

    // L[i] stores how many cells from row i are included in the left partition
    vector<int> L(n, 0);
    
    // We need to quickly access rows that can be extended.
    // A row i can be extended if L[i] < M and (i == n-1 or L[i] < L[i+1]).
    // We keep two buckets: rows that will give a '1' next, and rows that give '0'.
    vector<int> ones_moves;
    vector<int> zeros_moves;
    vector<bool> in_list(n, false);

    // Helper to check and add a row to the appropriate list
    auto check_and_add = [&](int r) {
        if (r < 0 || r >= n) return;
        if (in_list[r]) return; // Already in a list
        if (L[r] >= m) return;  // Row full

        // Condition: Bottom row always extendable, others need support from below
        if (r == n - 1 || L[r] < L[r+1]) {
            if (grid[r][L[r]] == 1) {
                ones_moves.push_back(r);
            } else {
                zeros_moves.push_back(r);
            }
            in_list[r] = true;
        }
    };

    // Initially, only the bottom row is potentially extendable (if n=1 or empty grid logic)
    // Actually, L array is all 0.
    // Condition L[i] < L[i+1] fails for all i < n-1 since 0 is not < 0.
    // So only row n-1 is valid initially.
    check_and_add(n - 1);

    while (current_ones < target) {
        int r = -1;
        
        // Strategy: Pick 1s if available
        if (!ones_moves.empty()) {
            r = ones_moves.back();
            ones_moves.pop_back();
        } else if (!zeros_moves.empty()) {
            // Must pick a 0 to unblock future moves
            r = zeros_moves.back();
            zeros_moves.pop_back();
        } else {
            // Should not happen if target is reachable (which it is)
            break;
        }

        in_list[r] = false; // We removed it from list to process

        // Double check validity (state might have changed? No, we only add if valid)
        // However, if we picked 'r', we increment L[r].
        // This might invalidate 'r' for the NEXT step (checked in add),
        // and it might VALIDATE 'r-1'.

        // Update state
        if (grid[r][L[r]] == 1) {
            current_ones++;
        }
        L[r]++;

        // After incrementing L[r]:
        // 1. Row 'r' might still be extendable (if L[r] is still valid relative to L[r+1])
        check_and_add(r);
        
        // 2. Row 'r-1' might have become extendable (since L[r] increased, support grew)
        check_and_add(r - 1);
    }

    // Output Result
    long long setA = current_ones;
    long long setB = total_ones - current_ones;
    cout << setA * setB << "\n";

    // Reconstruct Path
    // L[i] tells us the column index of the vertical cut in row i.
    // Path starts at (0,0).
    // For row 0: Move Right L[0] times, then Down.
    // For row 1: Move Right L[1]-L[0] times, then Down.
    // ...
    // For row n-1: Move Right L[n-1]-L[n-2] times, then Down.
    // Finally: Move Right M - L[n-1] times (to reach bottom-right corner).
    
    string path = "";
    int current_col = 0;
    for (int i = 0; i < n; ++i) {
        while (current_col < L[i]) {
            path += 'R';
            current_col++;
        }
        path += 'D';
    }
    while (current_col < m) {
        path += 'R';
        current_col++;
    }
    cout << path << "\n";
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