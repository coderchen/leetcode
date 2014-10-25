#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> retVec;
		if (digits.empty()) return retVec;

		int carry = 1;
		for_each(digits.rbegin(), digits.rend(), 
			[&carry, &retVec](int i) {
			int num = i + carry;
			carry = num / 10;
			num = num % 10;
			retVec.push_back(num);
		});
		if (carry) retVec.push_back(carry);
		reverse(retVec.begin(), retVec.end());
		return retVec;
	}
};

int main()
{
	return 0;
}