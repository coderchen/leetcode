class Solution {
public:
    int trap(int A[], int n) {
        int V = 0;
		for (int i = 0; i < n;) {
			while (i+1 < n && A[i+1] >= A[i])
				++i;
			
			int j = i + 1;
			if (j == n) break;
			int k = i + 1;
			while (j+1 < n) {
				++j;
				if (A[j] >= A[k]) {
					k = j;
					if (A[k] > A[i]) 
						break;
				}
			}
			
			int top = std::min(A[i], A[k]);
			int tmpV = (k-i-1) * top;
			for (int t = i+1; t < k; ++t) {
				tmpV -= std::min(A[t], top);
			}
			
			V += tmpV;
			i = k;
		}
		return V;
    }
};