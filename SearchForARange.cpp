	class Solution {
	public:
		vector<int> searchRange(int A[], int n, int target) {
			if (n <= 0) return vector<int>(2, -1);
			
			int l = 0;
			int r = n - 1;
			while (l < r) {
				int m = (l + r) / 2;
				if (A[m] < target) l = m + 1;
				else if (A[m] > target) r = m - 1;
				else {
					vector<int> vl = searchRange(&A[l], m - l + 1, target);
					vector<int> vr = searchRange(&A[m + 1], r - m, target);
					vector<int> retVec(2);
					retVec[0] = vl[0] + l;
					retVec[1] = (vr[0] != -1) ? (vr[1] + m + 1) : (vl[1] + l);
					return retVec;
				}
			}
			
			return (l == r && A[l] == target) ? vector<int>(2, l) :vector<int>(2, -1);
		}
	};