class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n <= 0) return false;
		
		int l = 0;
		int r = n - 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			if (A[m] == target) {
				return true;
			} else {
				if (A[l] < target && target < A[m]) r = m - 1;
				else if (A[m] < target && target < A[r]) l = m + 1;
				else {
					if (A[l] == target) return true;
					++l;
				}
			}
		}
		
		return A[l] == target;
    }
};

//amazing 线性搜索竟然也通过了
class Solution {
public:
	bool search(int A[], int n, int target) {
		for (int i = 0; i < n; ++i)
			if (A[i] == target) return true;
		return false;	
	}
};