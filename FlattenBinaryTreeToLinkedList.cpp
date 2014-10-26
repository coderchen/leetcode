#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归解法
class Solution_recursion {
private:
	TreeNode* _visit(TreeNode*& node, TreeNode* tail)
	{
		if (!node) return tail;

		node->right = _visit(node->right, tail);
		node->right = _visit(node->left, node->right);
		node->left = nullptr;

		return node;
	}

public:
	void flatten(TreeNode *root) {
		if (!root) return;
		_visit(root, nullptr);
	}
};

//非递归解法
class Solution {
public:
	void flatten(TreeNode *root) {
		while (root)
		{
			if (root->left)
			{
				TreeNode* node = root->left;
				while (node->right)
					node = node->right;
				node->right = root->right;
				root->right = root->left;
				root->left = nullptr;
			}
			root = root->right;
		}
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	Solution s;
	s.flatten(root);
	return 0;
}