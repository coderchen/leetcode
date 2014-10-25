#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void _visit(TreeNode* node, int curNum, int& sum)
	{
		if (!node) return;
		curNum = curNum * 10 + node->val;
		if (!node->left && !node->right)
		{
			sum += curNum;
			return;
		}
		_visit(node->left, curNum, sum);
		_visit(node->right, curNum, sum);
	}

public:
	int sumNumbers(TreeNode *root) {
		int sum = 0;
		_visit(root, 0, sum);
		return sum;
	}
};

int main()
{
	return 0;
}