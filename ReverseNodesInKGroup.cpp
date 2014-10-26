#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
private:
	//[bNode, eNode)
	ListNode* _reverse(ListNode* bNode, ListNode* eNode) {
		ListNode* head = eNode;
		while (bNode != eNode) {
			ListNode* node = bNode;
			bNode = bNode->next;
			node->next = head;
			head = node;
		}
		return head;
	}
	
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* pFirst = head;
		ListNode** pp = &head;
		
		while (1) {
			int i = 0;
			while (i < k && pFirst) {
				pFirst = pFirst->next;
				++i;
			}
			if (i < k) break;
			
			ListNode** pp2 = &(*pp)->next;
			*pp = _reverse(*pp, pFirst);
			pp = pp2;
		}
		
		return head;
    }
};

int main()
{
	return 0;
}