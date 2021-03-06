// Author thkim
//

#include <unordered_set>

using namespace std;

class Node
{
public:
	Node(Node* copy) 
	{
		if (!copy)
			return;
		if (s_visited.insert(copy).second)
		{
			m_val = copy->m_val;
			m_next = copy->m_next ? new Node(copy->m_next) : nullptr;
			m_random = copy->m_random ? new Node(copy->m_random) : nullptr;
		}		
	}
	int m_val;
	Node* m_next;
	Node* m_random;
	static unordered_set<Node*> s_visited;
};
