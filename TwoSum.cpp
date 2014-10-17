#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

//----------------------------------leetcode---------------------------------
class Solution {
	typedef tuple<int, int> IntTuple;
		
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		if (numbers.size() < 2) return result;

		vector<IntTuple> utilVec;
		for_each(numbers.begin(), numbers.end(), 
			[&utilVec](const int n){
			utilVec.push_back(IntTuple(n, utilVec.size() + 1));
		});

		sort(utilVec.begin(), utilVec.end(), 
			[](const IntTuple& p1, const IntTuple& p2){
			return get<0>(p1) < get<0>(p2);
		});

		int l = 0;
		int r = utilVec.size() - 1;

		while (l < r)
		{
			IntTuple& p1 = utilVec[l];
			IntTuple& p2 = utilVec[r];

			int sum = get<0>(p1) + get<0>(p2);
			if (sum == target)
			{
				result.push_back(std::min(get<1>(p1), get<1>(p2)));
				result.push_back(std::max(get<1>(p1), get<1>(p2)));
				break;
			}
			else if (sum < target)
				++l;
			else
				--r;
		}

		return result;
	}
};
//----------------------------------leetcode---------------------------------

//Test
#include <iostream>

int main()
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(7);
	vec.push_back(11);
	vec.push_back(15);
	Solution s;
	vector<int> result = s.twoSum(vec, 9);
	for (vector<int>::iterator it = result.begin();
		it != result.end(); ++it)
		std::cout << *it << std::endl;

	return 0;
}