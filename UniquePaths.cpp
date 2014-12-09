class Solution {
public:
    int uniquePaths(int m, int n) {
        if (--m == 0) return 1;
        if (--n == 0) return 1;
        
        int a = m + n;
        int b = std::min(m, n);
        long long c = 1;
        for (int i = b; i > 0; --i)
        {
            c *= a--;
        }
        long long d = 1;
        while (b > 0)
            d *= b--;
        
        return c/d;
    }
};

class Solution {
public:
	int uniquePaths(int m, int n) {
		std::vector<std::vector<int> > pathVec(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				if (i == 0 && j == 0) pathVec[i][j] = 1;
				else if (i == 0) pathVec[i][j] = pathVec[i][j-1];
				else if (j == 0) pathVec[i][j] = pathVec[i-1][j];
				else pathVec[i][j] = pathVec[i-1][j] + pathVec[i][j-1];
			}
		return pathVec[m-1][n-1];
	}
};