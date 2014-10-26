#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* p = head;
		while (p && p->next) {
			if (p->val == p->next->val) {
				ListNode* node = p->next;
				p->next = node->next;
				//delete or free `node` ???
			}
			else {
				p = p->next;
			}
		}
		return head;
    }
};


int main()
{
	return 0;
}