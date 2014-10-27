#include <iostream>
#include <queue>
#include <algorithm>

struct ListNode {
    int val;    
	ListNode *next;    
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* _merge(ListNode* l1, ListNode* l2) {
		ListNode* head = nullptr;
		ListNode** pp = &head;
		
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				*pp = l1;
				pp = &l1->next;
				l1 = l1->next;
			} else {
				*pp = l2;
				pp = &l2->next;
				l2 = l2->next;
			}
			*pp = nullptr;
		}
		
		if (l1) *pp = l1;
		if (l2) *pp = l2;
		
		return head;
	}
	
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		std::queue<ListNode*> q;
		std::for_each(lists.begin(), lists.end(),
			[&q](ListNode* node) { q.push(node); });
		
		while (q.size() > 1) {
			ListNode* l1 = q.front();
			q.pop();
			ListNode* l2 = q.front();
			q.pop();
			q.push(_merge(l1, l2));
		}
		
		return q.empty() ? nullptr : q.front();		
    }
};

int main()
{

	return 0;
}