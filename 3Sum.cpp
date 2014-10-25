#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > retVec;

		sort(num.begin(), num.end());
		for (int i = 0; i < (int)num.size(); ++i)
		{
			if (i != 0 && num[i] == num[i - 1])
				continue;
			int j = i + 1;
			int k = num.size() - 1;
			while (j < k)
			{
				if (j != i + 1 && num[j] == num[j - 1])
				{
					++j;
					continue;
				}

				int sum = num[i] + num[j] + num[k];
				if (sum == 0)
				{
					retVec.push_back(vector<int>());
					vector<int>& v = *(retVec.rbegin());
					v.push_back(num[i]);
					v.push_back(num[j]);
					v.push_back(num[k]);
					--k;
					++j;
				}
				else if (sum > 0)
					--k;
				else
					++j;
			}
		}

		return retVec;
	}
};

int main()
{
	return 0;
}