#include <iostream>
#include <cassert>
#include <cstring>
#include <algorithm>

//----------------------------------leetcode---------------------------------
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int t = m + n;
		if (t & 0x01)
			return findMinK(A, m, B, n, t / 2 + 1);
		return (findMinK(A, m, B, n, t / 2) + findMinK(A, m, B, n, t / 2 + 1)) / 2;
	}

private:
	double findMinK(int A[], int m, int B[], int n, int K)
	{
		if (m > n) 
			return findMinK(B, n, A, m, K);
		if (m == 0)
			return B[K - 1];
		if (K == 1)
			return std::min(A[0], B[0]);

		int cutA = std::min(K / 2, m);
		int cutB = K - cutA;

		if (A[cutA - 1] < B[cutB - 1])
		{
			return findMinK(A + cutA, m - cutA, B, n, K - cutA);
		}
		else if (A[cutA - 1] > B[cutB - 1])
		{
			return findMinK(A, m, B + cutB, n - cutB, K - cutB);
		}
		else
		{
			return A[cutA - 1];
		}
	}
};
//----------------------------------leetcode---------------------------------

int main()
{
	Solution s;
	int B1[] = { 1, 2 };
	assert(s.findMedianSortedArrays(nullptr, 0, B1, 2) - 1.5 < 0.00001);
	return 0;
}