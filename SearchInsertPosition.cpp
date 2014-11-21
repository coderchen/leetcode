class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		int first = 0;
		int last = n;
		while (first < last) {
			int cnt = last - first;
			int mid = first + (cnt>>1);
			if (A[mid] < target) first = mid + 1;
			else last = mid;			
		}
		return first;
    }
};