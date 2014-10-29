#include <map>
#include <set>
#include <vector>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;   
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
	map<UndirectedGraphNode*, UndirectedGraphNode*> oldNewMap;
	
	UndirectedGraphNode* _dfs(UndirectedGraphNode* node) {
		if (!node) return nullptr;
		
		UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
		oldNewMap[node] = newNode;
		for (UndirectedGraphNode* p : node->neighbors) {
			auto it = oldNewMap.find(p);
			if (it == oldNewMap.end()) {
				newNode->neighbors.push_back(_dfs(p));
			} else {
				newNode->neighbors.push_back(it->second);
			}
		}
		
		return newNode;
	}
	
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		oldNewMap.clear();
		return _dfs(node);
    }
};

int main() {
	return 0;
}