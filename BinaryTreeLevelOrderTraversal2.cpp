#include <vector>
#include <tuple>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	typedef tuple<TreeNode*, int> VisitTuple;
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > retVec;
		
		queue<VisitTuple> q;
		q.push(VisitTuple(root, 0));
		while (!q.empty())
		{
			VisitTuple vt = q.front();
			q.pop();
			TreeNode* node = get<0>(vt);
			if (!node) continue;

			int lvl = get<1>(vt);
			if (lvl == (int)retVec.size())
				retVec.push_back(vector<int>());
			retVec[lvl].push_back(node->val);

			q.push(VisitTuple(node->left, lvl + 1));
			q.push(VisitTuple(node->right, lvl + 1));
		}
		reverse(retVec.begin(), retVec.end());
		return retVec;
	}
};

int main()
{
	return 0;
}