#include <iostream>
#include <cstdarg>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		ListNode* newHead = nullptr;
		while (head)
		{
			ListNode* node = head;
			head = head->next;
			node->next == nullptr;
			_insert(&newHead, node);
		}
		return newHead;
	}

private:
	void _insert(ListNode** pp, ListNode* node)
	{
		while (*pp && (*pp)->val < node->val)
			pp = &(*pp)->next;
		node->next = *pp;
		*pp = node;
	}
};

int main()
{
	return 0;
}