class Solution {
	bool _care(char c) {
		return isdigit(c) || islower(c) || isupper(c);
	}
	
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
		
		size_t l = 0;
		size_t r = s.length() - 1;
		
		while (l < r) {
			if (!_care(s[l])) {
				++l;
				continue;
			}
			
			if (!_care(s[r])) {
				--r;
				continue;
			}
			
			if (tolower(s[l]) != tolower(s[r])) return false;
			
			++l;
			--r;
		}
		
		return true;
    }
};