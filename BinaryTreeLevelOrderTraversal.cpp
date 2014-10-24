#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	typedef std::tuple<int, TreeNode*> VisitTuple;

public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > retVec;
		if (!root) return retVec;

		queue<VisitTuple> q;
		q.push(VisitTuple(0, root));
		while (!q.empty())
		{
			VisitTuple vt = q.front();
			q.pop();
			int lvl = get<0>(vt);
			TreeNode* node = get<1>(vt);
			if (retVec.size() == lvl)
				retVec.push_back(vector<int>());
			vector<int>& v = retVec[lvl];
			v.push_back(node->val);
			if (node->left)
				q.push(VisitTuple(lvl + 1, node->left));
			if (node->right)
				q.push(VisitTuple(lvl + 1, node->right));
		}

		return retVec;
	}
};

int main()
{
	return 0;
}