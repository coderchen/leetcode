class Solution {
public:
    bool isValid(string s) {
		stack<char> charStack;
		for (size_t pos = 0; pos < s.length(); ++pos) {
			char c = s[pos];
			switch(c) {
				case '(':
				case '{':
				case '[':
					charStack.push(c);
					break;
				case ')': {
						if (!charStack.empty() && charStack.top() == '(')
							charStack.pop();
						else return false;
					}
					break;
				case '}': {
						if (!charStack.empty() && charStack.top() == '{')
							charStack.pop();
						else return false;
					}
					break;
				case ']': {
						if (!charStack.empty() && charStack.top() == '[')
							charStack.pop();
						else return false;
					}
					break;
				default:
					return false;
			}
		}
		
		return charStack.empty();
    }
};