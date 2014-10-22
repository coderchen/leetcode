#include <iostream>
#include <deque>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		if (head == nullptr) return;

		std::deque<ListNode*> nodeQueue;
		ListNode** pp = &head->next;
		head = head->next;
		while (head)
		{
			ListNode* tmpNode = head;
			head = head->next;
			tmpNode->next = nullptr;
			nodeQueue.push_back(tmpNode);
		}

		int flag = 0;
		while (!nodeQueue.empty())
		{
			ListNode* tmpNode = nullptr;
			if (flag & 0x01)
			{
				tmpNode = nodeQueue.front();
				nodeQueue.pop_front();
			}
			else
			{
				tmpNode = nodeQueue.back();
				nodeQueue.pop_back();
			}
			++flag;

			*pp = tmpNode;
			pp = &tmpNode->next;
		}
	}
};

int main()
{
	return 0;
}