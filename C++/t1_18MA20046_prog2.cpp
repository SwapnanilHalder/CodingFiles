#include<iostream>
#define DIFF 0.00000000001
#define int long long int
using namespace std;



double cubeRoot(int n) {
    double i=0, j=n;
    while(1) {
        double k = (i + j) / 2;
        double approx_cube = k*k*k;
        int difference = approx_cube - n;
        if (difference < 0) difference = -difference;

        if(difference <= DIFF) {
            int l = (int)k;
            if(l*l*l == n) return l;
            else return k;
        }
        if(approx_cube > n) j = k;
        else i = k;
    }
}

int32_t main() {
    int n;
    cout << "Enter the Number : ";
    cin >> n;
    double f = cubeRoot(n);
    cout << "Cubic Root : " << f<<endl;
}