#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define For(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) cout << i << " "; cout<<"\n"
#define pv2d(k) for(const auto &j: k) pv(j); cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

void selectionSort(vector<int> &A, int x, int y) {
    int key = 0, j = 0;
    for(int i = x+1; i <= (y) ; i++) {
        key = A[i];
        j = i-1;
        while(j >= x && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

vector<int> nextPermutation(vector<int> &A) {
    int n = A.size();
    int p = n-1;
    int local_small = INT_MAX;
    int local_small_idx = -1;
    while(A[p] < A[p-1]  &&   p >= 1 ) {
        p--;
    }
    if (p == 0) {
        selectionSort(A, 0, n-1);
        return A;
    }
    for(int i = p; i < n; i++) {
        if(A[i] > A[p-1]) {
            if(A[i] < local_small) {
                local_small = A[i];
                local_small_idx = i;
            }
        }
    }
    A[local_small_idx] = A[p-1];
    A[p-1] = local_small;
    selectionSort(A, p, n-1);
    return A;
}


int main() {
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    pv(nextPermutation(arr));
}