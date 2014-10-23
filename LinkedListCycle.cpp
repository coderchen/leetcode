#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		const ListNode* pFast = head;
		const ListNode* pSlow = head;
		while (pFast && pSlow)
		{
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (!pFast) break;
			pFast = pFast->next;

			if (pFast && pSlow && pFast == pSlow)
				return true;
		}

		return false;
	}
};


int main()
{

}
