class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
		
		int pos = 2;
		for (int i = 2; i < n; ++i) {
			if (A[i] == A[pos - 1] && A[i] == A[pos - 2]) 
				continue;
			A[pos++] = A[i];
		}
		
		return pos;
    }
};