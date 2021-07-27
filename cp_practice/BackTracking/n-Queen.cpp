// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> arr;
    vector<vector<int>> answer;
    int n;
    bool isSafe(int row,int col) {
        int count=0;
        for(int i=0; i<n; i++) {
            if (arr[row][i])
                return 0;
        }  
        int i = row, j = col;
        while( (i > 0) && (j > 0) ) {
            i--; j--;
            if(arr[i][j] == 1) 
                return 0;
        }
        i = row, j = col;
        while( (i < (n-1)) && (j > 0) ) {
            i++; j--;
            if(arr[i][j] == 1) 
                return 0;
        }
        return 1;
    }
    
    bool recurSolve(int col, int n) {
        if(col == n) {
            vector<int> V;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(arr[i][j] == 1) {
                        V.push_back(j+1);
                    }
                }
            }
            answer.push_back(V);
            return true;
        }
        bool res = 0;
        for(int row=0; row<n; row++) {
            if( isSafe(row, col) ) {
                arr[row][col] = 1;
                res =  (recurSolve(col+1, n) ) || res;
                arr[row][col] = 0;
            }
        }
        return res;
    }
    
    vector<vector<int>> nQueen(int k) {
        // code here
        arr.clear(); answer.clear();
        n = k;
        arr = vector<vector<int>>(n, vector<int> (n, 0));
        bool ans = recurSolve(0, n);
        if(ans == 0)
            return vector<vector<int>> ();
        sort(answer.begin(), answer.end());
        return answer;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends