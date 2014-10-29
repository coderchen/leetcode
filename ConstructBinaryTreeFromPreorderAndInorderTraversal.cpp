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
	typedef typename vector<int>::iterator _It;
private:
	TreeNode* _create(_It bPre, _It ePre, _It bIn, _It eIn) {
		if (bPre == ePre) return nullptr;
		
		int rootVal = *(bPre++);
		TreeNode* root = new TreeNode(rootVal);
		_It mIn = bIn;
		_It mPre = bPre;
		while (mIn != eIn && *mIn != rootVal) {
			++mIn;
			++mPre;
		}
		if (mIn != bIn) {
			root->left = _create(bPre, mPre, bIn, mIn);
		}
		if (mIn != eIn) {
			root->right = _create(mPre, ePre, mIn + 1, eIn);
		}
		return root;
	}
	
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return _create(preorder.begin(), preorder.end(), 
					inorder.begin(), inorder.end());
    }
};

int main()
{
	return 0;
}