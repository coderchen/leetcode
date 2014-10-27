#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode* lessHead = nullptr;
		ListNode** lessPP = &lessHead;
		ListNode* notLessHead = nullptr;
		ListNode** notLessPP = &notLessHead;
		
		while (head) {
			ListNode* node = head;
			head = head->next;
			node->next = nullptr;
			
			if (node->val < x) {
				*lessPP = node;
				lessPP = &node->next;
			} else {
				*notLessPP = node;
				notLessPP = &node->next;
			}
		}
		
		if (lessHead) {
			*lessPP = notLessHead;
		} else {
			lessHead = notLessHead;
		}
		
		return lessHead;
    }
};

int main()
{
	return 0;
}