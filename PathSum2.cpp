#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//----------------------------------leetcode---------------------------------
class Solution {
	typedef vector<int> PATH_TYPE;
	typedef vector<PATH_TYPE> RETURN_TYPE;

public:
	RETURN_TYPE pathSum(TreeNode *root, int sum) {
		RETURN_TYPE ret;
		PATH_TYPE pt;
		_pathSum(root, sum, 0, ret, pt);
		return ret;
	}

private:
	void _pathSum(TreeNode* node, int sum, int currSum, RETURN_TYPE& rt, PATH_TYPE& pt)
	{
		if (node == nullptr) return;

		pt.push_back(node->val);
		currSum += node->val;
		
		if (currSum == sum
			&& node->left == nullptr
			&& node->right == nullptr)
		{
			rt.push_back(pt);
		}

		_pathSum(node->left, sum, currSum, rt, pt);
		_pathSum(node->right, sum, currSum, rt, pt);

		pt.pop_back();
	}
};
//----------------------------------leetcode---------------------------------

int main()
{
	return 0;
}