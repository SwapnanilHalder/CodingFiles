/*

Count the triplets 
Easy Accuracy: 42.82% Submissions: 35841 Points: 2
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
 
Example 1:

Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: 2
Explanation: There are 2 triplets: 
1 + 2 = 3 and 3 +2 = 5 
â€‹Example 2:

Input: 
N = 3
arr[] = {2, 3, 4}
Output: 0
Explanation: No such triplet exits
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countTriplet() which takes the array arr[] and N as inputs and returns the triplet count

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 105

*/


#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define For(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) cout << i << " "; cout<<"\n"
#define pv2d(k) for(const auto &j: k) pv(j); cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	

	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	  	// vector<int> arr = {arr1, arr1+n};
        // int maxm = *max_element(arr.begin(), arr.end());
        int count = 0;
        sort(arr, arr + n);
        for(int i = n-1; i >= 2; i--){
            int j = 0, k = i-1;
            while(j < k){
                if(arr[j] + arr[k] > arr[i])
                    k--;
                else if(arr[j] + arr[k] < arr[i])
                    j++;
                else{
                    count++;
                    j++;
                    k--;
                }
            }
        }
        return count;

	}


	// int countTriplet(int arr1[], int n)
	// {

	    // vi arr = {arr1, arr1+n};
        // int maxm = *max_element(all(arr));
        // int freq[maxm + 1]={0};
        // For(i, 0, n) {
        //     freq[arr[i]]++;
        // }
        // int result = 0;
        // result += freq[0] * (freq[0]-1) * (freq[0]-2) / 6;  // 0,0,0

        // For(i, 1, maxm+1) {     
        //     result += freq[0] * freq[i] * (freq[i]-1)/2;    // 0,x,x
        // }

        // for (int i = 1; 2 * i <= maxm; i++) {
        //     result += freq[i] * (freq[i]-1) * freq[2*i]/ 2;  // x,x,2x
        // }
        // for(int i = 1; i < maxm+1; i++) {
        //     for(int j=i+1; (i+j) < maxm+1; j++) {
        //         result += freq[i] * freq[j] * freq[i+j];
        //     }
        // }
        // return result;
	// }
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends