#include <iostream>
#include <algorithm>
#include <cstdarg>
#include <list>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (head == nullptr) return nullptr;

		std::vector<ListNode*> listVec;

		while (head)
		{
			ListNode* node = head;
			head = head->next;
			node->next = nullptr;
		
			std::size_t i = 0;
			while (i < listVec.size() && listVec[i])
			{
				node = _merge(listVec[i], node);
				listVec[i++] = nullptr;
			}
			if (i == listVec.size()) listVec.push_back(node);
			else listVec[i] = node;
		}

		for (std::size_t i = 1; i < listVec.size(); ++i)
		{
			listVec[i] = _merge(listVec[i - 1], listVec[i]);
			listVec[i - 1] = nullptr;
		}

		return *(listVec.rbegin());
	}

private:
	ListNode* _merge(ListNode* l1, ListNode* l2)
	{
		ListNode* p = nullptr;
		ListNode** pp = &p;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				*pp = l1;
				pp = &l1->next;
				l1 = l1->next;
				*pp = nullptr;
			}
			else
			{
				*pp = l2;
				pp = &l2->next;
				l2 = l2->next;
				*pp = nullptr;
			}
		}

		*pp = l1 ? l1 : l2;
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
	ListNode* head = create_list(4, 4, 2, 1, 3);
	head = s.sortList(head);
	print_and_destroy(head);

	std::list<int> li;
	li.sort();
	return 0;
}