#include <iostream>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define END cout<<"\n"
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""


using namespace std;

int solve(int A, int B) {
    vector<vector<int>> chess(10, vector<int> (10, 0));
    for(int i{0}; i<10; i++) {
        chess[0][i] = -1;
        chess[9][i] = -1;
        chess[i][0] = -1;
        chess[i][9] = -1; 
    }
    
    chess[A][B] = 1;
    // pv2d(chess);
    int total_moves = 0;
    total_moves += min(A-1, B-1);
    total_moves += min(A-1, 8-B);
    total_moves += min(8-A, B-1);
    total_moves += min(8-A, 8-B);
    return total_moves;
}


int main() {
    cout << solve(1,1) << endl;
}