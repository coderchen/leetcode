class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		for (int i = (int)triangle.size() - 2; i >= 0; --i) {
			for (int j = 0; j < (int)triangle[i].size(); ++j) {
				triangle[i][j] += std::min(triangle[i+1][j], triangle[i+1][j+1]);
			}
		}
		return triangle[0][0];
    }
};