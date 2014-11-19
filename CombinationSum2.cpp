class Solution {
private:
	void solve(vector<vector<int> >& ans, vector<int>& rec, 
			vector<bool>& used, vector<int>& candidates, int target, int idx) {
		if (target == 0) {
			ans.push_back(rec);
			return;
		}
		
		if (idx == candidates.size() || candidates[idx] > target) {
			return;
		}
		
		if (idx > 0 && candidates[idx] == candidates[idx-1] && !used[idx-1]) {
			used[idx] = false;
			solve(ans, rec, used, candidates, target, idx+1);
		} else {
			for (int i = 1; i >= 0; --i)
				rec.push_back(candidates[idx]);
		
			for (int i = 1; i >= 0; --i) {
				rec.pop_back();
				used[idx] = i > 0;
				solve(ans, rec, used, candidates, target - candidates[idx] * i, idx + 1);
			}
		}		
	}
	
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> record;
		vector<bool> used(candidates.size(), false);
        solve(ans, record, used, candidates, target, 0);
        return ans;
    }
};