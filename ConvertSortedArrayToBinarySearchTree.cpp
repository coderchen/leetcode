#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
	TreeNode *left;
    TreeNode *right;  
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	TreeNode* _create(vector<int>& num, size_t bPos, size_t ePos) {
		if (bPos == ePos) return nullptr;
		
		size_t mPos = bPos + (ePos - bPos) / 2;
		TreeNode* root = new TreeNode(num[mPos]);
		root->left = _create(num, bPos, mPos);
		root->right = _create(num, mPos + 1, ePos);
		return root;
	}
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return _create(num, 0, num.size());
    }
};

int main()
{
	return 0;
}