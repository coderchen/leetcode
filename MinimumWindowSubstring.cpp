class Solution {
public:
    string minWindow(string S, string T) {
        if (S.length() < T.length() || T.empty()) return "";
			
		const int MAX_CHAR_CNT = 256;
		int hasFound[MAX_CHAR_CNT];
		int needToFind[MAX_CHAR_CNT];
		memset(hasFound, 0, sizeof(hasFound));
		memset(needToFind, 0, sizeof(needToFind));
		for (size_t i = 0; i < T.length(); ++i) {
			needToFind[(int)T[i]]++;
		}
		
		int minBeg = 0;
		int minLen = INT_MAX;
		int bPos = 0;
		int totalFound = 0;
		
		for (int e = 0; e < S.length(); ++e) {
			if (!needToFind[(int)S[e]]) continue;
			
			hasFound[(int)S[e]]++;
			if (hasFound[(int)S[e]] <= needToFind[(int)S[e]]) {
				totalFound++;
			}
			
			if (totalFound == T.length()) {
				while (bPos < e) {
					if (needToFind[(int)S[bPos]]) {
						if (hasFound[(int)S[bPos]] - 1 >= needToFind[(int)S[bPos]]) {
							hasFound[(int)S[bPos]]--;
						} else break;
					}
					++bPos;
				}
	
				if (minLen > e - bPos + 1) {
					minLen = e - bPos + 1;
					minBeg = bPos;
				}				
			}
		}
		
		if (totalFound != T.length()) return "";
		return string(S, minBeg, minLen);
    }
};