#include <bits/stdc++.h>

using namespace std;

void base(int n){
    int base7[32];   
    int i = 0; 
    while (n > 0) { 
  
        base7[i] = n % 7; 
        n = n / 7; 
        i++; 
    }   
    for (int j = i - 1; j >= 0; j--) 
        cout << base7[j];

};

int main() {
    int n = 40;
    base(n);
    
}