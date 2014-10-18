#include <iostream>
#include <cstdarg>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//----------------------------------leetcode---------------------------------
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* p = nullptr;
		ListNode** pp = &p;
		int carry = 0;
		while (l1 != nullptr || l2 != nullptr || carry)
		{
			int n1 = 0;
			if (l1 != nullptr)
			{
				n1 = l1->val;
				l1 = l1->next;
			}
			int n2 = 0;
			if (l2 != nullptr)
			{
				n2 = l2->val;
				l2 = l2->next;
			}

			int s = n1 + n2 + carry;
			carry = s / 10;
			s = s % 10;

			ListNode* node = new ListNode(s);
			*pp = node;
			pp = &node->next;
		}

		return p;
	}
};
//----------------------------------leetcode---------------------------------

void print_and_destroy(ListNode* l)
{
	while (l != nullptr)
	{
		std::cout << l->val << " ";
		ListNode* tmp = l;
		l = l->next;
		delete tmp;
	}
	std::cout << std::endl;
}

ListNode* create_list(int n, ...)
{
	ListNode* p = nullptr;
	ListNode** pp = &p;
	
	va_list vl;
	va_start(vl, n);
	for (int i = 0; i < n; ++i)
	{
		int val = va_arg(vl, int);
		ListNode* node = new ListNode(val);
		*pp = node;
		pp = &node->next;
	}

	return p;
}

int main()
{
	ListNode* l1 = nullptr;
	ListNode* l2 = nullptr;
	ListNode* l3 = nullptr;
	Solution s;

	l1 = create_list(2, 1, 8);
	l2 = create_list(1, 0);
	l3 = s.addTwoNumbers(l1, l2);
	print_and_destroy(l1);
	print_and_destroy(l2);
	print_and_destroy(l3);
	std::cout << "-----------" << std::endl;

	l1 = create_list(3, 2, 4, 3);
	l2 = create_list(3, 5, 6, 4);
	l3 = s.addTwoNumbers(l1, l2);
	print_and_destroy(l1);
	print_and_destroy(l2);
	print_and_destroy(l3);
	std::cout << "-----------" << std::endl;


	l1 = create_list(5, 1, 2, 9, 9, 8);
	l2 = create_list(3, 5, 6, 4);
	l3 = s.addTwoNumbers(l1, l2);
	print_and_destroy(l1);
	print_and_destroy(l2);
	print_and_destroy(l3);
	std::cout << "-----------" << std::endl;

	return 0;
}