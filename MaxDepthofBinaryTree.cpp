#include <iostream>
#include <algorithm>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return std::max(lh, rh) + 1;
    }
};

int main()
{
	return 0;
}