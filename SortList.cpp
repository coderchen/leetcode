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
		if (!head || !head->next) return head;

		const std::size_t _MaxBin = 32;
		ListNode* _BinList[_MaxBin];
		memset(_BinList, 0, sizeof(_BinList));
		std::size_t _CurBin = 0;

		while (head)
		{
			ListNode* node = head;
			head = head->next;
			node->next = nullptr;
		
			std::size_t i = 0;
			while (i < _CurBin && _BinList[i])
			{
				node = _merge(node, _BinList[i]);
				_BinList[i++] = nullptr;
			}
			if (i == _MaxBin)
				_BinList[_MaxBin - 1] = _merge(_BinList[_MaxBin - 1], node);
			else
			{
				_BinList[i] = node;
				if (i == _CurBin) ++_CurBin;
			}
		}

		for (std::size_t i = 1; i < _CurBin; ++i)
		{
			_BinList[i] = _merge(_BinList[i], _BinList[i - 1]);
			_BinList[i - 1] = nullptr;
		}
		
		return _BinList[_CurBin - 1];
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