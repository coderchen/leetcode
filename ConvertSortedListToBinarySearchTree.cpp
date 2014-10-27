#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* toTree(ListNode* bNode, ListNode* eNode) {
		int size = 0;
		ListNode* p = nullptr;
		for (p = bNode; p != eNode; p = p->next)
			++size;
		if (size == 0) 
			return nullptr;
		
		p = bNode;
		for (int i = 0; i < size / 2; ++i)
			 p = p->next;
		TreeNode* root = new TreeNode(p->val);
		root->left = toTree(bNode, p);
		root->right = toTree(p->next, eNode);
		return root;
	}
	
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return toTree(head, nullptr);
    }
};

int main()
{
	return 0;
}