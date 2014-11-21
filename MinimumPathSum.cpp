class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		size_t m = grid.size();
		size_t n = grid[0].size();
		vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
		for (size_t i = 1; i <= m; ++i)
			for (size_t j = 1; j <= n; ++j)
				if (i == 1) dp[i][j] = dp[i][j-1] + grid[i-1][j-1];
				else if (j == 1) dp[i][j] = dp[i-1][j] + grid[i-1][j-1];
				else dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i-1][j-1];
		
		return dp[m][n];
    }
};