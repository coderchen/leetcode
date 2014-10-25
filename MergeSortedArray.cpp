#include <iostream>

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int pos = m + n - 1;
		--m;
		--n;
		while (m >= 0 && n >= 0)
			A[pos--] = A[m] >= B[n] ? A[m--] : B[n--];
		while (m >= 0)
			A[pos--] = A[m--];
		while (n >= 0)
			A[pos--] = A[n--];
	}
};

int main()
{
	return 0;
}