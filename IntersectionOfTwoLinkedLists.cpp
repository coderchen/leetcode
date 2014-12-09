/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
		
		int len1 = 0;
		int len2 = 0;
		ListNode* p1 = headA;
		ListNode* p2 = headB;
		while (p1) {
			++len1;
			p1 = p1->next;
		}
		while (p2) {
			++len2;
			p2 = p2->next;
		}
		
		p1 = headA;
		p2 = headB;
		
		for (int i = 0; i < len1 - len2; ++i)
			p1 = p1->next;
		for (int i = 0; i < len2 - len1; ++i)
			p2 = p2->next;
		
		while (p1 && p2 && p1 != p2) {
			p1 = p1->next;
			p2 = p2->next;
		}
		
		return p1 && p2 ? p1 : nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
		ListNode* p1 = headA;
		ListNode* p2 = headB;
		bool p1Switched = false;
		bool p2Switched = false;
		while (p1 && p2 && p1 != p2) {
			if (p1->next) {
				p1 = p1->next;
			} else if (!p1Switched) {
				p1Switched = true;
				p1 = headB;
			} else {
				p1 = nullptr;
			}
			
			if (p2->next) {
				p2 = p2->next;
			} else if (!p2Switched) {
				p2Switched = true;
				p2 = headA;
			} else {
				p2 = nullptr;
			}
		}
		return p1 && p2 ? p1 : nullptr;
    }
};