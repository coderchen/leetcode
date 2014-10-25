#include <vector>
#include <tuple>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	typedef tuple<TreeNode*, bool, bool> VisitTuple;
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> retVec;

		stack<VisitTuple> s;
		s.push(VisitTuple(root, false, false));
		while (!s.empty())
		{
			VisitTuple& vt = s.top();
			if (!get<0>(vt))
			{
				s.pop();
				continue;
			}

			if (!get<1>(vt))
			{
				get<1>(vt) = true;
				s.push(VisitTuple(get<0>(vt)->left, false, false));
			}
			else if (!get<2>(vt))
			{
				get<2>(vt) = true;
				retVec.push_back(get<0>(vt)->val);
				s.push(VisitTuple(get<0>(vt)->right, false, false));
			}
			else
				s.pop();
		}
		return retVec;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	Solution s;
	vector<int> v;
	v = s.inorderTraversal(root);
	return 0;
}