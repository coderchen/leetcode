class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		std::sort(S.begin(), S.end());
        vector<vector<int> > retVec;
		retVec.push_back(vector<int>());
		int lastUnused = 0;
		for (int i = 0; i < (int)S.size(); ++i) {
			int cnt = (int)retVec.size();
			for (int j = 0; j < cnt; ++j) {
				if (i != 0 && S[i] == S[i-1] && j < lastUnused)
					continue;
				retVec.push_back(retVec[j]);
				retVec.back().push_back(S[i]);
			}
			lastUnused = cnt;
		}
		return retVec;
    }
};