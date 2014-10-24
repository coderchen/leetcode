#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> retVec;
		if (!root) return retVec;

		stack<VisitTuple> s;
		s.push(VisitTuple(root, false, false));
		retVec.push_back(root->val);
		while (!s.empty())
		{
			VisitTuple& vt = s.top();
			if (!get<1>(vt))
			{
				get<1>(vt) = true;
				if (get<0>(vt)->left)
				{
					retVec.push_back(get<0>(vt)->left->val);
					s.push(VisitTuple(get<0>(vt)->left, false, false));
				}
			}
			else if (!get<2>(vt))
			{
				get<2>(vt) = true;
				if (get<0>(vt)->right)
				{
					retVec.push_back(get<0>(vt)->right->val);
					s.push(VisitTuple(get<0>(vt)->right, false, false));
				}
			}
			else
			{
				s.pop();
			}
		}
		
		return retVec;
	}
};

int main()
{
	return 0;
}