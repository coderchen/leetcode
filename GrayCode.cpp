class Solution {
public:
    vector<int> grayCode(int n) {
		if (n <= 0) return vector<int>(1, 0);
		vector<int> result;
		result.push_back(0);
		result.push_back(1);
		for (int i = 2; i <= n; ++i) {
			int prev = (int)result.size();
			int flag = 1 << (i-1);
			while (--prev >= 0) {
				result.push_back(result[prev] | flag);
			}
		}
		return result;
    }
};