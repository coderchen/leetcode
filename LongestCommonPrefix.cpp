#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty()) return string();
		size_t maxLen = SIZE_MAX;
		for_each(strs.begin(), strs.end(), [&maxLen](const string& s){
			maxLen = min(maxLen, s.length());
		});
		if (maxLen == 0) return string();

		size_t pos = 0;
		stringstream stream;
		while (pos < maxLen)
		{
			vector<string>::iterator it = strs.begin();
			char c = (*it)[pos];
			while (++it != strs.end())
			{
				if ((*it)[pos] != c) break;
			}
			if (it != strs.end()) break;
			stream << c;
			++pos;
		}

		return stream.str();
	}
};

int main()
{
	vector<string> v;
	v.push_back("a");
	Solution s;
	s.longestCommonPrefix(v);
	return 0;
}

