#include <cassert>
#include <cstddef>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//----------------------------------leetcode---------------------------------
class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		return _hashPathSum(root, sum, 0);
	}

private:
	bool _hashPathSum(TreeNode* node, int sum, int currSum)
	{
		if (node == nullptr) return false;

		currSum += node->val;
		if (currSum == sum 
			&& node->left == nullptr 
			&& node->right == nullptr)
			return true;

		if (_hashPathSum(node->left, sum, currSum)
			|| _hashPathSum(node->right, sum, currSum))
			return true;

		return false;
	}
};
//----------------------------------leetcode---------------------------------

int main()
{

	return 0;
}