class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int left = 0;
		int top = 0;
		int right = (int)matrix.size() - 1;
		int bottom = (int)matrix.size() - 1;
		
		while (left < right && top < bottom) {
			for (int i = left + 1; i < right; ++i) {
				swap(matrix[top][i], matrix[i][right]);
			}
			for (int i = left + 1; i < right; ++i) {
				swap(matrix[top][right - (i-left)], matrix[bottom][i]);
			}
			
			for (int i = left + 1; i < right; ++i) {
				swap(matrix[top][right - (i-left)], matrix[i][left]);
			}
			
			swap(matrix[top][left], matrix[top][right]);
			swap(matrix[top][left], matrix[bottom][right]);
			swap(matrix[top][left], matrix[bottom][left]);
			
			++left; ++top; --right; --bottom;
		}
    }
};