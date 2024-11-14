#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

int total = 0;

bool isAttacking(int x1, int y1, int x2, int y2) {
    int x_diff = abs(x1 - x2);
    int y_diff = abs(y1 - y2);

    if(x_diff == 0 || y_diff == 0 || x_diff == y_diff) return true;
    return false;
}

bool Attacked(vector<vector<char>> &chessboard, int x, int y) {
    For(i, 0, x) {
        For(j, 0, 8) {
            if(chessboard[i][j] == 'o' && isAttacking(x, y, i, j)) return true;
        }
    }
    // pl("not attacked");
    return false;
}

void nqueen(vector<vector<char>> &chessboard, int next_row) {
    // cout << "NEXT_ROW: " << next_row << endl;
    if(next_row == 8) {
        total++;
        return;
    }
    For(i, 0, 8) {
        // cout << "Trying : " << next_row << " , " << i << endl;
        if(chessboard[next_row][i] == '.' && !Attacked(chessboard, next_row, i)) {
            chessboard[next_row][i] = 'o';
            nqueen(chessboard, next_row+1);
            chessboard[next_row][i] = '.';
        }
    }
}

void solve() {
    vector<vector<char>> chessboard(8, vector<char>(8, '.'));
    string a;
    For(i, 0, 8) {
        cin >> a;
        For(j, 0, 8) {
            chessboard[i][j] = a[j];
        }
    }

    For(i, 0, 8) {
        if(chessboard[0][i] == '.') {
            chessboard[0][i] = 'o';
            // cout << "Filled up " << 0 << " , " << i << endl;
            nqueen(chessboard, 1);
            chessboard[0][i] = '.';
        }
    }
    cout << total << endl;
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