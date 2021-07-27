// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int maxm=0;
    int local_max;
    void DFS(int x, int y, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        cout << "Entered : " << x << " ; " << y ;
        visited[x][y] = 1;
        local_max++;
        cout << "   local max : " << local_max<<endl;
        if(local_max > maxm)
            maxm = local_max;
        for(int i=x-1; i<= x+1; i++) {
            for(int j=y-1; j<= y+1; j++) {
                if(i >= 0 && i < visited.size() && j>=0 && j < visited[0].size()) {
                    if((!visited[i][j]) && grid[i][j] ) {
                        cout << " => " << x << ", " << y << " sending : ";
                        DFS(i, j, visited, grid);
                    }
                    
                }
            }
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited (m, vector<int> (n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((!visited[i][j]) && grid[i][j]) {
                    local_max = 0;
                    DFS(i, j, visited, grid);
                }
            }
        }
        return maxm;
    }
    
};


/*

1
10 6
0 1 0 0 0 0
0 0 1 0 1 0
0 0 0 0 0 1
0 0 0 0 1 1
0 1 0 0 0 0
0 0 0 0 0 0
0 1 1 0 0 0
0 1 0 0 0 1
1 1 1 0 0 0
1 0 1 0 0 0

*/

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends