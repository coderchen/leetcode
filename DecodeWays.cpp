
class Solution {
	//[bPos, ePos]
	int process(string& s, int bPos, int ePos) {
		int ePos_copy = ePos;
		
		vector<int> numVec(ePos - bPos + 1, 0);
		numVec[ePos - bPos] = 1;
		--ePos;
		
		while (ePos >= bPos) {
			if (s[ePos] == '1' || (s[ePos] == '2' && s[ePos + 1] < '7')) {
				numVec[ePos - bPos] = numVec[ePos - bPos + 1] + 
					(ePos_copy - ePos >= 2) ? numVec[ePos - bPos + 2] : 1;
			} else {
				numVec[ePos - bPos] = numVec[ePos - bPos + 1];
			}
			--ePos;
		}
		return numVec[0];
	}
	
public:
    int numDecodings(string s) {
		if (s.empty()) return 0;
		
		int cnt = 0;
		int ePos = (int)s.length() - 1;
		while (ePos >= 0) {
			while (ePos >= 0 && !(s[ePos] <= '9' && s[ePos] >= '1')) {
				--ePos;
			}
			if (ePos < 0) break;
			
			int a = 0;
			int b = 0;
			
			int bPos = ePos;
			while (bPos > 0 && s[bPos - 1] <= '9' && s[bPos - 1] >= '1') {
				
				--bPos;
			}
			
			int partCnt = process(s, bPos, ePos);
			cnt = cnt ? cnt * partCnt : partCnt;
			
			ePos = bPos - 1;
		}
		
		return cnt;
    }
};