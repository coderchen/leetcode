class Solution {
public:
    int jump(int A[], int n) {
		int step = 0;
		for (int i = 0; i < n;) {
			if (i == n-1) break;
			else if (i + A[i] >= n-1) {
				++step;
				break;
			} else {
				if (A[i] == 0) return 0;
				int longest = 0;
				int nextJumpPos = i;
				for (int l = A[i]; l >= 1; --l) {
					if (i+l+A[i+l] > longest) {
						longest = i+l+A[i+l];
						nextJumpPos = i + l;
					}
				}
				
				++step;
				i = nextJumpPos;
			}
		}
		return step;
    }
};