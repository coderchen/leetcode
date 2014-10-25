#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int _getMin(TreeNode* node)
	{
		while (node->left) node = node->left;
		return node->val;
	}
	int _getMax(TreeNode* node)
	{
		while (node->right) node = node->right;
		return node->val;
	}

public:
	bool isValidBST(TreeNode *root) {
		if (!root) return true;
		if (root->left)
		{
			if (!isValidBST(root->left)) return false;
			if (!(root->val > _getMax(root->left))) return false;
		}
		if (root->right)
		{
			if (!isValidBST(root->right)) return false;
			if (!(root->val < _getMin(root->right))) return false;
		}
		
		return true;
	}
};

int main()
{
	return 0;
}