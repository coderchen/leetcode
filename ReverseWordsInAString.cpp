#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		const char* buf = s.c_str();
		string tmp;
		for (std::size_t sPos = 0; sPos < s.length(); ++sPos)
		{
			if (buf[sPos] == ' ') continue;
			std::size_t ePos = sPos + 1;
			while (ePos < s.length() && buf[ePos] != ' ')
				++ePos;

			tmp = tmp.empty() 
				? string(&buf[sPos], ePos - sPos)
				: string(&buf[sPos], ePos - sPos) + ' ' + tmp;
			sPos = ePos;
		}
		s.swap(tmp);
	}
};

int main()
{
	Solution s;
	string str = "   the sky is   blue   ";
	s.reverseWords(str);
	std::cout << str << std::endl;
	return 0;
}