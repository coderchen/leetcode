class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
		
		int m = (int)matrix.size();
		int n = (int)matrix[0].size();
		
		bool zeroFirstRow = false;
		bool zeroFirstCol = false;
		
		for (int i = 0; i < m; ++i) {
			if (matrix[i][0] == 0) zeroFirstCol = true;
		}
		for (int i = 0; i < n; ++i) {
			if (matrix[0][i] == 0) zeroFirstRow = true;
		}
		
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		
		for (int i = 1; i < m; ++i) {
			if (matrix[i][0] == 0) {
				for (int j = 1; j < n; ++j) {
					matrix[i][j] = 0;
				}
			}
		}
		
		for (int j = 1; j < n; ++j) {
			if (matrix[0][j] == 0) {
				for (int i = 1; i < m; ++i) {
					matrix[i][j] = 0;
				}
			}
		}
		
		if (zeroFirstRow) {
			for (int i = 0; i < n; ++i) {
				matrix[0][i] = 0;
			}
		}
		if (zeroFirstCol) {
			for (int i = 0; i < m; ++i) {
				matrix[i][0] = 0;
			}
		}
    }
};