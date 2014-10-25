#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n == 0) return "";

		string retString("1");
		for (int i = 1; i < n; ++i)
		{
			stringstream stream;
			size_t cnt = 0;
			for (size_t pos = 0; pos <= retString.length();)
			{
				if (cnt == 0 || retString[pos] == retString[pos - 1])
				{
					++cnt;
					++pos;
				}
				else
				{
					stream << cnt << retString[pos - 1];
					cnt = 0;
				}
			}
			retString = stream.str();
		}

		return retString;
	}
};

int main()
{
	Solution s;
	s.countAndSay(3);
	return 0;
}