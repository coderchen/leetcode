#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//----------------------------------leetcode---------------------------------
class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if (!root) return true;

		int lh = 0;
		int rh = 0;
		bool lBalance = _isBalanced(root->left, lh);
		bool rBalance = _isBalanced(root->right, rh);

		int dh = lh - rh;
		return lBalance && rBalance && dh >= -1 && dh <= 1;
	}

private:
	bool _isBalanced(TreeNode* node, int& h)
	{
		if (!node)
		{
			h = 0;
			return true;
		}

		int lh = 0;
		int rh = 0;
		bool lBalance = _isBalanced(node->left, lh);
		bool rBalance = _isBalanced(node->right, rh);

		int dh = lh - rh;
		h = std::max(lh, rh) + 1;
		return lBalance && rBalance && dh >= -1 && dh <= 1;

	}
};
//----------------------------------leetcode---------------------------------

int main()
{
	return 0;
}