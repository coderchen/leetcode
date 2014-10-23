#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* pSlow = head;
		ListNode* pFast = head;
		while (pSlow && pFast)
		{
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (!pFast) break;
			pFast = pFast->next;

			if (pSlow == pFast) break;
		}
		if (!pSlow || !pFast || pSlow != pFast) return nullptr;

		ListNode* head1 = head;
		ListNode* head2 = pFast->next;
		ListNode* head2_copy = pFast->next;
		pFast->next = nullptr;
		int len1 = 0;
		int len2 = 0;
		for (ListNode* node = head1; node; node = node->next)
			++len1;
		for (ListNode* node = head2; node; node = node->next)
			++len2;
		for (int i = len1 - len2; i > 0; --i)
			head1 = head1->next;
		for (int i = len2 - len1; i > 0; --i)
			head2 = head2->next;

		while (head1 != head2)
		{
			head1 = head1->next;
			head2 = head2->next;
		}
		pFast->next = head2_copy;
		return head1;
	}
};


int main()
{
	return 0;
}