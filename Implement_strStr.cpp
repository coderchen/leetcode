
/*
 * sunday算法, 请扔掉落后的KMP
 */
 
class Solution {
public:
    int strStr(char *haystack, char *needle) {
		int len1 = strlen(haystack);
		int len2 = strlen(needle);
		
		const int MAX_CHAR_CNT = 256;
		int lastPos[MAX_CHAR_CNT];
		for (int i = 0; i < MAX_CHAR_CNT; ++i) {
			lastPos[i] = -1;
		}
		for (int i = 0; i < len2; ++i) {
			int idx = (int)needle[i];
			lastPos[idx] = i;
		}
		
		for (int i = 0; i <= len1 - len2; ) {
			int j = 0;
			while (j < len2) {
				if (haystack[i] == needle[j]) {
					++i;
					++j;
				} else {
					int curEndPos = i + (len2 - j);
					int idx = (int)haystack[curEndPos];
					if (lastPos[idx] == -1) {
						i = curEndPos + 1;
					} else {
						i = curEndPos - lastPos[idx];				
					}
					break;				
				}
			}
			
			if (j == len2) {
				return i - len2;
			}	
		}
		return -1;
    }
};