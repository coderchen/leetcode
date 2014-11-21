class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int i = -1;
        for (; i + 1 < (int)matrix.size() && matrix[i + 1][0] <= target; ++i)
			;
		return i >= 0 
			&& i < (int)matrix.size() 
			&& binary_search(matrix[i].begin(), matrix[i].end(), target);
    }
};