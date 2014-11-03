

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		
		bool first = true;
		int ret = 0;
		
		for (size_t i = 0; i < num.size(); ++i) {
			size_t j = i + 1;
			size_t k = num.size() - 1;
			while (j < k) {
				int sum = num[i] + num[j] + num[k];
				if (first || abs(sum - target) < abs(ret - target)) {
					first = false;
					ret = sum;
				}
				
				if (sum > target) --k;
				else if (sum < target) ++j;
				else return sum;
			}
		}
		
		return ret;
	}
};