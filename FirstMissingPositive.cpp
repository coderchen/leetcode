class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int pos = 0; pos < n;) {
			if (A[pos] > 0 
				&& A[pos] <= n 
				&& A[pos] != pos + 1
				&& A[pos] != A[A[pos] - 1]) {
				swap(A[pos], A[A[pos] - 1]);
			} else {
				++pos;
			}
		}
		
		for (int i = 0; i < n; ++i)
			if (A[i] != i + 1) return i + 1;
		return n + 1;
    }
};