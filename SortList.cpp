#include <iostream>
#include <algorithm>
#include <cstdarg>
#include <list>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (head == nullptr) return nullptr;

		ListNode* listTmp = nullptr;
		ListNode* listCounter[64];
		for (int i = 0; i < 64; ++i)
			listCounter[i] = nullptr;

		int fill = 0;
		while (head)
		{
			listTmp = head;
			head = head->next;
			listTmp->next = nullptr;

			int i = 0;
			while (i < fill && listCounter[i] != nullptr)
			{
				listTmp = _merge(listTmp, listCounter[i]);
				listCounter[i++] = nullptr;
			}

			listCounter[i] = listTmp;
			if (i == fill)
				++fill;
		}

		for (int i = 1; i < fill; ++i)
		{
			if (listCounter[i - 1] != nullptr || listCounter[i] != nullptr)
			{
				listCounter[i] = _merge(listCounter[i - 1], listCounter[i]);
				listCounter[i - 1] = nullptr;
			}
		}

		return listCounter[fill - 1];
	}

private:
	ListNode* _merge(ListNode* l1, ListNode* l2)
	{
		ListNode* p = nullptr;
		ListNode** pp = &p;

		while (l1 || l2)
		{
			ListNode** pList = nullptr;
			if (l1 && l2)
				pList = l1->val <= l2->val ? &l1 : &l2;
			else
				pList = l1 ? &l1 : &l2;

			ListNode* tmpNode = *pList;
			*pList = (*pList)->next;
			tmpNode->next = nullptr;
			*pp = tmpNode;
			pp = &tmpNode->next;
		}

		return p;
	}
};

ListNode* create_list(int n, ...)
{
	ListNode* head = nullptr;
	va_list vl;
	va_start(vl, n);
	for (int i = 0; i < n; ++i)
	{
		int e = va_arg(vl, int);
		ListNode* node = new ListNode(e);
		node->next = head;
		head = node;
	}

	return head;
}

void print_and_destroy(ListNode* head)
{
	while (head)
	{
		std::cout << head->val << " ";
		ListNode* tmp = head;
		head = head->next;
		delete tmp;
	}

	std::cout << std::endl;
}

int main()
{
	Solution s;
	ListNode* head = create_list(3, 3, 2, 4);
	head = s.sortList(head);
	print_and_destroy(head);

	std::list<int> li;
	li.sort();
	return 0;
}