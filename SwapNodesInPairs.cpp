#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	//递归求解
    ListNode *swapPairs_recursion(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
	
	//非递归求解
    ListNode *swapPairs(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode** pp = &newHead;
        while (head) {
            if (!head->next) {
                *pp = head;
                break;
            } else {
                *pp = head->next;
                head->next = (*pp)->next;
                (*pp)->next = head;
                pp = &head->next;
                head = head->next;
            }
        }
        return newHead;
    }
};

int main()
{
	return 0;
}