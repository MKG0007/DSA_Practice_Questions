/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        unordered_map<int , ListNode*> m;
        ListNode* temp = head;
        while(temp != NULL){
            if(m.find(temp->val) != m.end()){
                ListNode* dnode = temp;
                m[temp->val]->next = dnode->next;
                temp  = temp->next;
                dnode->next = NULL;
                delete dnode;
            }
            else{
                m[temp->val] = temp;
                temp = temp->next;
            }
        }

        return head;
        
    }
};