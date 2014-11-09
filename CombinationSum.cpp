class Solution {
private:
	void solve(vector<vector<int> >& ans, vector<int>& rec, vector<int>& candidates, int target, int idx) {
		if (target == 0) {
			ans.push_back(rec);
			return;
		}
		
		if (idx == candidates.size() || candidates[idx] > target) {
			return;
		}
		
		for (int i = target / candidates[idx]; i >= 0; --i)
			rec.push_back(candidates[idx]);
		
		for (int i = target / candidates[idx]; i >= 0; --i) {
			rec.pop_back();
			solve(ans, rec, candidates, target - candidates[idx] * i, idx + 1);
		}
	}
	
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        vector<vector<int> > ans;
        vector<int> record;
        solve(ans, record, candidates, target, 0);
        return ans;
    }
};