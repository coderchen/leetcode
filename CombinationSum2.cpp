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
		
		vector<int>::iterator it1 = lower_bound(candidates.begin(), candidates.end(), candidates[idx]);
		int diff1 = it1 - candidates.begin();
		int cnt = idx - diff1 + 1;
		
		for (int i = 1; i >= 0; --i)
			rec.push_back(candidates[idx]);
		
		for (int i = 1; i >= 0; --i) {
			rec.pop_back();
			vector<int>::iterator it2 = lower_bound(rec.begin(), rec.end(), candidates[idx]);
			int cnt2 = rec.end() - it2;
			if (cnt > cnt2 && cnt > 1) continue;
			solve(ans, rec, candidates, target - candidates[idx] * i, idx + 1);
		}
	}
	
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> record;
        solve(ans, record, candidates, target, 0);
        return ans;
    }
};