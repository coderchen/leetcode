#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int> > retVec;

		for (int i = 0; i < (int)num.size(); ++i)
		{
			if (i != 0 && num[i] == num[i - 1])
				continue;
			for (int j = i + 1; j < (int)num.size(); ++j)
			{
				if (j != i + 1 && num[j] == num[j - 1])
					continue;
				int l = j + 1;
				int r = (int)num.size() - 1;
				while (l < r)
				{
					if (l != j + 1 && num[l] == num[l - 1])
					{
						++l;
						continue;
					}

					int sum = num[i] + num[j] + num[l] + num[r];
					if (sum == target)
					{
						retVec.push_back(vector<int>());
						vector<int>& v = *(retVec.rbegin());
						v.push_back(num[i]);
						v.push_back(num[j]);
						v.push_back(num[l]);
						v.push_back(num[r]);
						++l;
						--r;
					}
					else if (sum > target)
						--r;
					else
						++l;
				}
			}
		}

		return retVec;
	}
};

int main()
{
	return 0;
}
