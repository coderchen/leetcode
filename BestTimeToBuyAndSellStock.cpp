
/*
动态规划
对于N个元素的数组a，找出i,j
使得0≤ i < j < N，并且a[j] - a[i]的值最大
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) return 0;
		
        int profit = INT_MIN;
		int minPrice = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			int tmpProfit = prices[i] - minPrice;
			profit = max(profit, tmpProfit);
			minPrice = min(minPrice, prices[i]);		
		}
		
		return max(profit, 0);
    }
};