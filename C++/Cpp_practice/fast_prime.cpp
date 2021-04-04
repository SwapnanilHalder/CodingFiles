#include<iostream>

using namespace std;

long long int count{0};


int main() {
    long long int n = 10000;
    for(long long int num = 1; num <= n; num++) {
        bool isPrime = true;
        if(num == 1) {
            isPrime = false;
            // cout << "Entered 1"<<endl;
        }
        if(num ==2 || num == 3) {
            isPrime = true;
            // cout << num <<"Entered 2 3"<<endl;
        }

        if((num %2==0 || num %3 == 0) && (num != 2 && num != 3) ){
            isPrime = false;
            // cout << num <<"Entered %2 %3"<<endl;
        } 

        for(long long int i{5}; i*i <= num; i += 6) {
            if((num % (i) == 0 || num% (i+2) == 0 ) && num >=5) {
                isPrime = false;
                // cout << num<< "entered 5 7\n"; 
            }
        }
        
        if(isPrime == true) {
            // cout << num << " ";
            count++;
            // cout << "entered last \n";
        }
    }
    cout << count << "\n";
}