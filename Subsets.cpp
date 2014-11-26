class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        std::sort(S.begin(), S.end());
		vector<vector<int> > retVec;
		retVec.push_back(vector<int>());
		for (auto i : S) {
			int cnt = (int)retVec.size();
			for (int j = 0; j < cnt; ++j) {
				retVec.push_back(retVec[j]);
				retVec.back().push_back(i);
			}
		}
		return retVec;
    }
};