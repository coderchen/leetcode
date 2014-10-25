#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (!head || k == 0) return head;

		ListNode* p1 = head;
		for (int i = 0; i < k; ++i)
			p1 = p1->next ? p1->next : head;
		if (p1 == head) return head;
		
		ListNode* p2 = head;
		while (p1->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		ListNode* newHead = p2->next;
		p2->next = nullptr;
		p1->next = head;
		return newHead;
	}
};

int main()
{
	return 0;
}