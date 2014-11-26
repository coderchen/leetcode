class Solution {
public:
    int trap(int A[], int n) {
        int V = 0;
		for (int i = 0; i < n;) {
			while (i+1 < n && A[i+1] >=A[i])
				++i;
			
			int j = i + 1;
			if (j >= n) break;
			while (j+1 < n && A[j+1] <= A[j])
				++j;
			
			int k = j + 1;
			while (k+1 < n && A[k+1] >= A[k])
				++k;
			if (k >= n) break;
			
			//[i, k]
			int top = std::min(A[i], A[k]);
			int tempV = (k-i-1) * std::min(A[i], A[k]);
			for (int p = i + 1; p < k; ++p) {
				tempV -= std::min(A[p], top);
			}
			
			V += tempV;
			i = k;
		}
		
		return V;
    }
};