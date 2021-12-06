#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n == 1) {
            // printf("n = %d ; k = %d ; returning => %d\n", n, k, 1);
            return 1;
        }
        int temp = (findTheWinner(n-1, k));
        // printf("n = %d ; k = %d ; returning => %d ; converting to => %d\n", n, k, temp, ((temp + k-1) % n )+1 );        
        return ((temp + k-1) % n )+1;
    }
    
};


int main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.findTheWinner(6, 5) << endl;
}