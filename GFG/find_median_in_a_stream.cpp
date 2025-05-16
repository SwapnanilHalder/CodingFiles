//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int, vector<int>, less<int>> first;
        priority_queue<int, vector<int>, greater<int>> second;

        vector<double> ans;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            second.push(arr[i]);
            int temp = second.top();
            first.push(temp);
            second.pop();
            if(first.size() > second.size()) {
                int temp1 = first.top();
                second.push(temp1);
                first.pop();
            }
            if(i&1) {
                ans.push_back(((double)first.top()+second.top())/2.0);
            } else {
                ans.push_back(second.top());
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends

