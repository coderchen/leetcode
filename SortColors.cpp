class Solution {
	enum { RED, WHITE, BLUE, COLOR_CNT };
	
public:
    void sortColors(int A[], int n) {
        int util[COLOR_CNT];
		memset(util, 0, sizeof(util));
		for (int i = 0; i < n; ++i)
			util[A[i]]++;
		
		util[BLUE] = util[RED] + util[WHITE];
		util[WHITE] = util[RED];
		util[RED] = 0;
		
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			v[util[A[i]]++] = A[i];
		}
		
		copy(v.begin(), v.end(), A);
    }
};