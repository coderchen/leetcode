#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
	typedef std::map<RandomListNode*, RandomListNode*> NodeMap;
	typedef std::vector<RandomListNode*> NodeVec;
	typedef std::map<RandomListNode*, NodeVec> UpdateMap;
	
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        NodeMap nodeMap;
		UpdateMap updateMap;
		RandomListNode* newHead = nullptr;
		RandomListNode** pp = &newHead;
		
		while (head) {
			RandomListNode* pOld = head;
			head = head->next;
	
			RandomListNode* pNew = nullptr;
			{
				NodeMap::iterator it = nodeMap.find(pOld);
				if (it != nodeMap.end()) {
					pNew = it->second;
				} else {
					pNew = new RandomListNode(pOld->label);
					nodeMap[pOld] = pNew;
				}
				*pp = pNew;
				pp = &(pNew->next);
			}
			
			{
				UpdateMap::iterator it = updateMap.find(pOld);
				if (it != updateMap.end()) {
					NodeVec& v = it->second;
					std::for_each(v.begin(), v.end(),
					[pNew](RandomListNode* p) {
						p->random = pNew;
					});
				}
			}
					
			if (!pOld->random) continue;

			{
				NodeMap::iterator it = nodeMap.find(pOld->random);
				if (it != nodeMap.end()) {
					pNew->random = it->second;
				} else {
					updateMap[pOld->random].push_back(pNew);
				}
			}
		}
		
		return newHead;
    }
};

int main()
{
	return 0;
}