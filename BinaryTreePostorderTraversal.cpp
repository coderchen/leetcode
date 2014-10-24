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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> retVec;
		if (root == nullptr) return retVec;
		stack<VisitTuple> s;
		s.push(VisitTuple(root, false, false));

		while (!s.empty())
		{
			VisitTuple& vt = s.top();
			if (!get<1>(vt))
			{
				get<1>(vt) = true;
				if (get<0>(vt)->left != nullptr)
				{
					s.push(VisitTuple(get<0>(vt)->left, false, false));
				}
			}
			else if (!get<2>(vt))
			{
				get<2>(vt) = true;
				if (get<0>(vt)->right != nullptr)
				{
					s.push(VisitTuple(get<0>(vt)->right, false, false));
				}
			}
			else
			{
				retVec.push_back(get<0>(vt)->val);
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