#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m == n) return head;
		
		ListNode** pp = &head;
		for (int i = 1; i < m; ++i)
			pp = &(*pp)->next;
		
		ListNode* pBeg = nullptr;
		ListNode* pEnd = nullptr;
		for (int i = m; i <= n; ++i) {
			ListNode* node = *pp;
			*pp = node->next;
			node->next = pBeg;
			pBeg = node;
			
			if (i == m) {
				pEnd = node;
			} 
			if (i == n) {
				pEnd->next = *pp;
				*pp = pBeg;
			}
		}
		
		return head;
    }
};

int main()
{
	return 0;
}