#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution_recursively {
public:
	bool isSymmetric(TreeNode *root) {
		if (!root) return true;
		return _check(root->left, root->right);
	}

private:
	bool _check(TreeNode* root1, TreeNode* root2)
	{
		if (!root1 && !root2) return true;
		if (root1 && root2)
		{
			bool bOuter = _check(root1->left, root2->right);
			if (!bOuter) return false;
			bool bInner = _check(root1->right, root2->left);
			if (!bInner) return false;

			return root1->val == root2->val;
		}
		else
			return false;
	}

};

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if (!root) return true;
		
		std::deque<TreeNode*> lQueue;
		std::deque<TreeNode*> rQueue;

		lQueue.push_back(root->left);
		rQueue.push_back(root->right);

		while (!lQueue.empty() && !rQueue.empty())
		{
			TreeNode* lNode = lQueue.front();
			lQueue.pop_front();
			TreeNode* rNode = rQueue.front();
			rQueue.pop_front();
			if (!lNode && !rNode) continue;
			if (lNode && rNode)
			{
				if (lNode->val != rNode->val)
					return false;
				lQueue.push_back(lNode->left);
				lQueue.push_back(lNode->right);
				rQueue.push_back(rNode->right);
				rQueue.push_back(rNode->left);
			}
			else
				return false;
		}

		return true;
	}
};

int main()
{
	return 0;
}