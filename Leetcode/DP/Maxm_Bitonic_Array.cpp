#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
	
	int findMaximum(vector<int> &arr, int n) {
	    // code here
       int start = 0, end = n-1, mid =0;
       if(n == 1) {
           return arr[0];
       }
       while(start <= end) {
           mid = start + (end-start)/2;
           if(mid > 0 && mid < n-1) {
               if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]) {
                   return arr[mid];
               }
               else if(arr[mid] >= arr[mid-1] && arr[mid] <= arr[mid+1]) {
                   start = mid+1;
               }
               else if(arr[mid] <= arr[mid-1] && arr[mid] >= arr[mid+1]) {
                   end = mid-1;
               }
               else {
                   end = mid-1;
               }
           }
           if(mid == 0) {
               if(arr[mid] >= arr[mid+1]) {
                   return arr[mid];
               }
               else {
                   return arr[mid+1];
               }
           }
           if(mid == n-1) {
               if(arr[mid] >= arr[mid-1]) {
                   return arr[mid];
               }
               else {
                   return arr[mid-1];
               }
           }
       }
       return -1;               
	}
};


int main() {
    Solution mySolution;
    vector<int> arr{2, 2,2 };
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.findMaximum(arr, arr.size()) << endl;
}