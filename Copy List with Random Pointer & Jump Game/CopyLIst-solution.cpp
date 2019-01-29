/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        unordered_map<RandomListNode*, RandomListNode*> hash;
        RandomListNode* node = head;
        while(node)
        {
            RandomListNode* newNode = new RandomListNode(node->label);
            hash.insert(make_pair(node, newNode));
            node = node->next;
        }

        RandomListNode* newHead = hash[head];
        node = head;
        while(node)
        {
            RandomListNode* newNode = hash[node];
            newNode->next = hash[node->next];
            newNode->random = hash[node->random];
            node = node->next;
        }
        
        return newHead;
    }
};