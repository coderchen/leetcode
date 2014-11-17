class Solution {
public:
    void nextPermutation(vector<int> &num) {
		if (num.size() <= 1) return;
        
		int i = (int)num.size() - 1;
		while (i > 0 && num[i] <= num[i-1])
			--i;
		if (i == 0) {
			reverse(num.begin(), num.end());
			return;
		}
		
		--i;
		int j = (int)num.size() - 1;
		while (!(num[i] < num[j])) 
			--j;
		
		swap(num[i], num[j]);
		reverse(num.begin() + i + 1, num.end());
    }
};