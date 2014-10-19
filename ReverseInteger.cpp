#include <cassert>

//----------------------------------leetcode---------------------------------
class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		bool bNegative = false;
		if (x < 0)
		{
			x = -x;
			bNegative = true;
		}

		while (x > 0)
		{
			ret = ret * 10 + x % 10;
			x = x / 10;
		}

		return bNegative ? -ret : ret;
	}
};
//----------------------------------leetcode---------------------------------

//Test Case
int main()
{
	Solution s;

	assert(s.reverse(321) == 123);
	assert(s.reverse(0) == 0);
	assert(s.reverse(-321) == -123);
	return 0;
}