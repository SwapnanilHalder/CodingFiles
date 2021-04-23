#include <iostream>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define END cout<<"\n"
#define deb(x) cout << '\t'<<#x << " = " << x << endl

using namespace std;

int maxArr(vector<int> &A) {
    int max = -99999999;
    int temp = 0;
    int n = A.size();
    for(int i{0}; i< n-1; i++) {
        for (int j {i+1}; j<n; j++) {
            temp = abs(A[i] - A[j]) + abs(i-j);
            if (temp > max) {
                max = temp;
            }
        }
    }
    return max;
}

int main() {
    vector<int> A = {5,2,7,-1,3,-2};
    cout << maxArr(A) << endl;
}