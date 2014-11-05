class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (!s) return 0;
		int len = 0;
		while (*s) {
			bool bClear = false;
			while (*s && *s == ' ') {
				++s;
				bClear = true;
			}
			if (!*s) break;
			
			len = bClear ? 1 : len + 1;
			++s;
		}
		
		return len;
    }
};