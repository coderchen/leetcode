class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix;
		if (n <= 0) return matrix;
		
		int left = 0;
		int top = 0;
		int right = n - 1;
		int bottom = n - 1;
		int element = 1;
		
		matrix.resize(n);
		for (auto& v : matrix) v.resize(n);
		
		while (left <= right && top <= bottom) {
			for (int i = left; i <= right; ++i) {
				matrix[top][i] = element++;
			}
			for (int i = top + 1; i < bottom; ++i) {
				matrix[i][right] = element++;
			}
			for (int i = right; i >= left && top != bottom; --i) {
				matrix[bottom][i] = element++;
			}
			for (int i = bottom - 1; i > top && left != right; --i) {
				matrix[i][left] = element++;
			}
			
			++left; ++top; --right; --bottom;
		}
		return matrix;
    }
};