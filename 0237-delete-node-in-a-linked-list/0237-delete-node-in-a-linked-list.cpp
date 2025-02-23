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
    void deleteNode(ListNode* node) {

        ListNode* newNode = node->next;
        node->val = newNode->val;
        node->next = node->next->next;
        newNode->next = NULL;
        delete newNode;
        
    }
};