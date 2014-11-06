class Solution {
public:
	int sqrt(int x) {
		unsigned long long int l = 1;
		unsigned long long int h = x;
		while (l < h) {
			unsigned long long m = l+ (h - l) / 2;
			unsigned long long multiply = m * m;
			if (multiply > x) {
				h = m - 1;
			} else if (multiply < x) {
				l = m + 1;
			} else {
				return m;
			}
		}

		return h * h > x ? h - 1 : h;
	}
};