#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* newHead = nullptr;
		ListNode** pp = &newHead;
		
		while (l1 && l2) {
			ListNode* node = nullptr;
			if (l1->val <= l2->val) {
				node = l1;
				l1 = l1->next;
				node->next = nullptr;
			} else {
				node = l2;
				l2 = l2->next;
				node->next = nullptr;
			}
			
			*pp = node;
			pp = &node->next;
		}
		
		if (l1) *pp = l1;
		if (l2) *pp = l2;
		
		return newHead;
    }
};

int main()
{
	return 0;
}