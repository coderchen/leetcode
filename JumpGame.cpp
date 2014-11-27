class Solution {
public:
	bool canJump(int A[], int n) {
		if (n <= 0) return false;
		std::vector<bool> canFlag(n, false);
		canFlag[n-1] = true;
		for (int i = n-2; i >= 0; --i) {
			bool curPosCan = false;
			for (int l = std::min(A[i], n-1-i); l >= 1; --l) {
				if (canFlag[i+l]) {
					curPosCan = true;
					break;
				}
			}
			canFlag[i] = curPosCan;
		}
		return canFlag[0];
	}
};

class Solution {
public:
	bool canJump(int A[], int n) {
		if (n <= 0) return false;
		
		int step = A[0];
		for (int i = 1; i < n; ++i) {
			if (step == 0) return false;
			step = std::max(step-1, A[i]);
		}
		
		return true;
	}
}