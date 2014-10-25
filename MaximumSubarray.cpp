#include <iostream>
#include <algorithm>

class Solution {
public:
	int maxSubArray(int A[], int n) {
		int retMax = A[0];
		int curMax = A[0];
		for (int i = 1; i < n; ++i)
		{
			curMax = std::max(curMax, 0);
			curMax = curMax + A[i];
			retMax = std::max(retMax, curMax);
		}
		return retMax;
	}
};

int main()
{
	return 0;
}