// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum
// path in the grid
int MaximumPath(vector<vector<int> >& grid)
{
	// Dimensions of grid[][]
	int N = grid.size();
	int M = grid[0].size();

	// Stores maximum sum at each cell
	// sum[i][j] from cell sum[0][0]
	vector<vector<int> > sum;
	sum.resize(N + 1,
			vector<int>(M + 1));

	// Iterate to compute the maximum
	// sum path in the grid
	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= M; j++) {

			// Update the maximum path sum
			sum[i][j] = max(sum[i - 1][j],
							sum[i][j - 1])
						+ grid[i - 1][j - 1];
		}
	}

	// Return the maximum sum
	return sum[N][M];
}

// Driver Code
int main()
{
	vector<vector<int> > grid
		= { { 1, 2 }, { 3, 5 } };

	cout << MaximumPath(grid);

	return 0;
}
