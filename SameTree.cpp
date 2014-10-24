#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (!p && !q) return true;
		if (!p) return false;
		if (!q) return false;

		return p->val == q->val 
			&& isSameTree(p->left, q->left) 
			&& isSameTree(p->right, q->right);
	}
};

int main()
{
	return 0;
}