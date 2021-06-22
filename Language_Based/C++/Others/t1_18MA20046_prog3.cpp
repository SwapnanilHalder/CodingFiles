#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string s = "";

void printSumsHelper(int n, string sss) {
    if (n==0){
        cout << sss << endl;
        return;
    }

    for (int i=1; i<=n; ++i) {
        string s = "";
        ostringstream ss;
        s = s + sss;
        string k = to_string(i);
        s = s + k;
        s = s + " ";
        printSumsHelper(n - i, s);
    }
}

void printSums(int n){
    printSumsHelper(n, "");
}

int main() {
    int n ;
    cin >> n;
    printSums(n);
}