class Solution {
public:
    int search(int A[], int n, int target) {
        if (n <= 0) return -1;
		
		int l = 0;
		int r = n - 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			if (A[m] == target) {
				return m;
			} else if (A[m] > target) {
				if (A[m] < A[r]) r = m;
				else {
					if (A[l] <= target) r = m;
					else l = m + 1;
				}
			} else {
				if (A[m] < A[r]) {
					if (A[r] >= target) l = m + 1;
					else r = m;
				} else {
					l = m + 1;
				}	
			}
		}
		
		return A[l] == target ? l : -1;
    }
};