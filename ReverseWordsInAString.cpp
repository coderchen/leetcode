#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		stack<string> strStack;

		size_t pos1 = 0;
		size_t pos2 = 0;
		while (1)
		{
			pos1 = s.find_first_not_of(' ', pos2);
			if (pos1 == string::npos) break;
			pos2 = s.find_first_of(' ', pos1);

			strStack.push(s.substr(pos1, pos2 == string::npos ? s.length() - pos1 : pos2 - pos1));
		}

		s.clear();
		if (strStack.empty()) return;
		while (!strStack.empty())
		{
			s += strStack.top() + ' ';
			strStack.pop();
		}

		s.erase(s.length() - 1);
	}
};

int main()
{
	std::string str = " the sky is blue ";
	Solution s;
	s.reverseWords(str);
	std::cout << str << std::endl;
	return 0;
}