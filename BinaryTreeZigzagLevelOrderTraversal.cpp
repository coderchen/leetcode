/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > retVec;
		queue<TreeNode*> q;
		if (root) q.push(root);
		
		int flag = 0;
		while (!q.empty()) {
			retVec.push_back(vector<int>());
			vector<int>& v = *retVec.rbegin();
			
			std::size_t cnt = q.size();
			for (std::size_t i = 0; i < cnt; ++i) {
				TreeNode* node = q.front();
				q.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
				v.push_back(node->val);
			}
			
			if (flag) {
				reverse(v.begin(), v.end());
				flag = 0;
			} else {
				flag = 1;
			}
		}
		
		return retVec;
    }
};