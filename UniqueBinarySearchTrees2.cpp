#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<TreeNode*> _create(int sElem, int eElem)
	{
		vector<TreeNode*> retVec;
		if (sElem > eElem)
		{
			retVec.push_back(nullptr);
			return retVec;
		}

		for (int e = sElem; e <= eElem; ++e)
		{
			vector<TreeNode*> lTreeVec = _create(sElem, e - 1);
			vector<TreeNode*> rTreeVec = _create(e + 1, eElem);
			for (auto lNode : lTreeVec)
			{
				for (auto rNode : rTreeVec)
				{
					TreeNode* root = new TreeNode(e);
					root->left = lNode;
					root->right = rNode;
					retVec.push_back(root);
				}
			}
		}

		return retVec;
	}

public:
	vector<TreeNode *> generateTrees(int n) {
		return _create(1, n);
	}
};

int main()
{
	return 0;
}
