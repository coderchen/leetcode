class Solution {
public:
    int maxArea(vector<int> &height) {
        int cap = 0;
		int l = 0;
		int r = (int)height.size() - 1;
		
		while (l < r) {
			int v = min(height[l], height[r]) * (r - l);
			cap = max(cap, v);
			if (height[l] < height[r]) ++l;
			else --r;
		}
		
		return cap;
    }
};