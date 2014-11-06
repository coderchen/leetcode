class Solution {
public:
    int findMin(vector<int> &num) {
        size_t l = 0;
		size_t r = num.size() - 1;
		
		while (l < r) {
			if (num[l] < num[r]) break;
			
			 size_t m = l + (r - l) / 2;
			 if (num[m] > num[r]) l = m + 1;
			 else r = m;
		}
		
		return num[l];
    }
};