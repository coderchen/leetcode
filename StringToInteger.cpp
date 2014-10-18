#include <cassert>
#include <algorithm>

//----------------------------------leetcode---------------------------------
class Solution {
public:
	int atoi(const char *str) {
		if (str == nullptr) return 0;

		long long result = 0;
		bool bNegative = false;

		while (*str == ' ')
			++str;
		if (*str == '+' || *str == '-')
		{
			bNegative = *str == '-';
			++str;
		}
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
			str++;
		}

		if (bNegative) result *= -1;
		result = std::min(result, (long long)INT_MAX);
		result = std::max(result, (long long)INT_MIN);
		return (int)result;
	}
};
//----------------------------------leetcode---------------------------------
//Test Case
int main()
{
	Solution s;
	assert(s.atoi(nullptr) == 0);
	assert(s.atoi("5") == 5);
	assert(s.atoi(" 5 02") == 5);
	assert(s.atoi("+5") == 5);
	assert(s.atoi("-5") == -5);
	assert(s.atoi("5.01") == 5);
	assert(s.atoi("+5.01") == 5);
	assert(s.atoi("-5.01") == -5);
	assert(s.atoi("+0.01") == 0);
	assert(s.atoi("-0.01") == 0);
	assert(s.atoi("-0.0 1") == 0);
	assert(s.atoi("   010") == 10);
	assert(s.atoi("   +0 123") == 0);
	assert(s.atoi("2147483648") == 2147483647);
	assert(s.atoi("  - 321") == 0);
	assert(s.atoi("  + - 321") == 0);
	assert(s.atoi("  +- 321") == 0);
	return 0;
}