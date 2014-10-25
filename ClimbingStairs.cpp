#include <iostream>

class Solution {
public:
	int climbStairs(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;

		int a = 1; //n - 1
		int b = 2; //n
		for (int i = 3; i <= n; ++i)
		{
			int c = b + a;
			a = b;
			b = c;
		}
		return b;
	}
};

int main()
{
	return 0;
}