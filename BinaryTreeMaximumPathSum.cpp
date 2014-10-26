#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	void _visit(TreeNode* root, int& maxSum, int& pathSum) {
		if (!root) {
			maxSum = 0;
			pathSum = 0;
		}
		else {
			int _lMaxSum = INT_MIN;
			int _lPathSum = 0;
			if (root->left) {
				_visit(root->left, _lMaxSum, _lPathSum);
			}

			int _rMaxSum = INT_MIN;
			int _rPathSum = 0;
			if (root->right) {
				_visit(root->right, _rMaxSum, _rPathSum);
			}

			maxSum = max(_lMaxSum, _rMaxSum);
			int curSum = max(_lPathSum, 0) + root->val + max(_rPathSum, 0);
			maxSum = max(curSum, maxSum);

			pathSum = max(max(_lPathSum, _rPathSum), 0) + root->val;
		}
	}

public:
	int maxPathSum(TreeNode *root) {
		int maxSum = 0;
		int pathSum = 0;
		_visit(root, maxSum, pathSum);
		return maxSum;
	}
};

int main()
{
	return 0;
}