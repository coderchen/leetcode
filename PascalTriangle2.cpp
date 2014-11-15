class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) return vector<int>();
		vector<int> retVec(rowIndex + 1);
		for (int r = 0; r <= rowIndex; ++r) {
			int cnt = r + 1;
			for (int j = cnt - 1; j >= 0; --j) {
				if (j == cnt - 1 || j == 0) {
					retVec[j] = 1;
				} else {
					retVec[j] = retVec[j] + retVec[j - 1];
				}
			}
		}
		return retVec;
    }
};