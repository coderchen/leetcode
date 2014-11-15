class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > retVec(numRows);
		for (int i = 1; i <= numRows; ++i) {
			for (int j = 0; j < i; ++j) {
				if (j == 0 || j == i - 1) {
					retVec[i - 1].push_back(1);	
				} else {
					vector<int>& upVec = retVec[i - 2];
					retVec[i - 1].push_back(upVec[j - 1] + upVec[j]);
				}
			}
		}
		return retVec;
    }
};