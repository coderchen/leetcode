#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		ListNode** pp = &head;

		bool bDelete = false;
		while (*pp) {
			if (!(*pp)->next) {
				if (bDelete) *pp = nullptr;
				break;
			}
			
			if ((*pp)->val == (*pp)->next->val) {
				bDelete = true;
				(*pp)->next = (*pp)->next->next;
			} else if (bDelete) {
				*pp = (*pp)->next;
				bDelete = false;
			} else {
				pp = &(*pp)->next;
			}
		}

		return head;
    }
};


int main()
{
	return 0;
}