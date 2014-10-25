#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (!head) return nullptr;

		ListNode* p1 = head;
		for (int i = 0; i < n; ++i)
			p1 = p1->next;

		if (!p1) return head->next;

		ListNode* p2 = head;
		while (p1->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		p2->next = p2->next->next;
		return head;
	}
};

int main()
{
	return 0;
}