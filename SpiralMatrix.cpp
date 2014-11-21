class Solution {
private:
	void solve(vector<vector<int> >& matrix, 
		int left, int top, int right, int bottom, vector<int>& result) {
			if (left > right || top > bottom) return;
			
			for (int i = left; i <= right; ++i) {
				result.push_back(matrix[top][i]);
			}
			for (int i = top + 1; i < bottom; ++i) {
				result.push_back(matrix[i][right]);
			}
			for (int i = right; i >= left && top != bottom; --i) {
				result.push_back(matrix[bottom][i]);
			}
			for (int i = bottom - 1; i > top && left != right; --i) {
				result.push_back(matrix[i][left]);
			}
			
			//tail recursion
			solve(matrix, left + 1, top + 1, right - 1, bottom - 1, result);
	}
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
		if (matrix.empty()) return result;
		
		int left = 0;
		int top = 0;
		int right = (int)matrix[0].size() - 1;
		int bottom = (int) matrix.size() - 1;
		solve(matrix, left, top, right, bottom, result);
		return result;
    }
};