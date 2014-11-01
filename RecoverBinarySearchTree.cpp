#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* pre;
    TreeNode* p1;
    TreeNode* p2;
    
    void _visit(TreeNode* node) {
        if (!node) return;
        _visit(node->left);
        if (pre && pre->val > node->val) {
            if (!p1) p1 = pre;
            p2 = node;
        }
        pre = node;
        _visit(node->right);
    }
public:
    void recoverTree(TreeNode *root) {
        pre = p1 = p2 = nullptr;
        _visit(root);
        if (p1 && p2)
            std::swap(p1->val, p2->val);
    }
};

int main()
{
	return 0;
}