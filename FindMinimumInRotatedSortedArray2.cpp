class Solution {
public:
    int findMin(vector<int> &num) {
        size_t l = 0;
		size_t r = num.size() - 1;
		
		while (l < r) {		
			 size_t m = l + (r - l) / 2;
			 if (l == m) return min(num[l], num[r]);
			 
			 if (num[m] > num[r]) {
				l = m + 1;
			} else if (num[m] == num[r]) {
				while (l < m && num[l] == num[m])
					++l;
				if (l != m) r = m;
			} else {
				r = m;
			}
		}
		
		return num[l];
    }
};