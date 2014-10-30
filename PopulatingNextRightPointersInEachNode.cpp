#include <iostream>
#include <deque>

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
		
		std::deque<TreeLinkNode*> q;
		q.push_back(root);
		while (!q.empty()) {
			std::size_t cnt = q.size();
			std::size_t pos = 1;
			while (pos <= cnt) {
				TreeLinkNode* node = q.front();
				q.pop_front();
				node->next = (pos++ == cnt) ? nullptr : q.front();
				if (node->left)
					q.push_back(node->left);
				if (node->right)
					q.push_back(node->right);
			}
		}
    }
};

int main()
{
	return 0;
}