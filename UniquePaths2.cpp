class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
		
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		std::vector<std::vector<int> > pathVec(m, std::vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 && j == 0) pathVec[i][j] = 1;
				else if (i == 0) pathVec[i][j] = pathVec[i][j-1];
				else if (j == 0) pathVec[i][j] = pathVec[i-1][j];
				else pathVec[i][j] = pathVec[i-1][j] + pathVec[i][j-1];
				
				if (obstacleGrid[i][j]) pathVec[i][j] = 0;
			}
		}
		return pathVec[m-1][n-1];
    }
};