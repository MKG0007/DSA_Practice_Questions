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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* oddhead = new ListNode(0);  
        ListNode* evenhead = new ListNode(0); 
        ListNode* otemp = oddhead;
        ListNode* etemp = evenhead;
        ListNode* temp = head;

        while(temp != NULL){
            otemp->next = temp;
            temp = temp->next;
            otemp = otemp->next;
            etemp->next = temp;
            if(temp == NULL){break;}
            temp = temp->next;
            etemp = etemp->next;
        }

        otemp->next = evenhead->next;

        return oddhead->next;

    }
};
