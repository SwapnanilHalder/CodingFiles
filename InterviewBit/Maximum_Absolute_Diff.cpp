#include <iostream>
#include <vector>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<b;i++)
#define END cout<<"\n"
#define deb(x) cout << '\t'<<#x << " = " << x << endl

using namespace std;

int maxArr(vector<int> &A) {
    int n = A.size();
    vector<int> pos_add (n, 0);
    vector<int> pos_sub (n, 0);
    For(i, 0, n) {
        pos_add[i] = A[i] + i+1;
        pos_sub[i] = A[i] -(i+1);
    }
    int pos_add_max = abs(*max_element(pos_add.begin(), pos_add.end()) - *min_element(pos_add.begin(), pos_add.end()) );
    int pos_sub_max = abs(*max_element(pos_sub.begin(), pos_sub.end()) - *min_element(pos_sub.begin(), pos_sub.end()) );
    return max (pos_add_max, pos_sub_max);
}

int main() {
    vector<int> A = { 1,3,-1};
    cout << maxArr(A) << endl;
}