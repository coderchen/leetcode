#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* _create(vector<int>& inorder, size_t bInPos, size_t eInPos,
					vector<int>& postorder, size_t bPostPos, size_t ePostPos) {
		if (bInPos == eInPos) return nullptr;
		
		int rootVal = postorder[--ePostPos];
		TreeNode* root = new TreeNode(rootVal);
		size_t mInPos = bInPos;
		size_t mPostPos = bPostPos;
		while (mInPos != eInPos && inorder[mInPos] != rootVal) {
			++mInPos;
			++mPostPos;
		}
		if (mInPos != bInPos)
			root->left = _create(inorder, bInPos, mInPos,
							postorder, bPostPos, mPostPos);
		if (mInPos != eInPos)
			root->right = _create(inorder, mInPos + 1, eInPos,
							postorder, mPostPos, ePostPos);
							
		return root;					
	}
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return _create(inorder, 0, inorder.size(),
					postorder, 0, postorder.size());
    }
};

int main()
{
	return 0;
}