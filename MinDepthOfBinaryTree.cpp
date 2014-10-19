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
	int minDepth(TreeNode *root) {
		if (root == nullptr) return 0;
		if (!root->left && !root->right) return 1;

		int minld = root->left ? minDepth(root->left) : INT_MAX;
		int minrd = root->right ? minDepth(root->right) : INT_MAX;

		return std::min(minld, minrd) + 1;
	}
};
//----------------------------------leetcode---------------------------------

int main()
{
	return 0;
}