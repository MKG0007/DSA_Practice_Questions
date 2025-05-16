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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }

        if(size<n || n<0) return head;
        else if(size == n){
            ListNode* dnode = head;
            head = head->next;
            dnode->next = NULL;
            delete dnode;
        }
        else{
            temp = head;
            int pos = size-n;

            for(int i = 1 ; i<=pos-1 ; i++){
                temp = temp->next;
            }

            ListNode* dnode = temp->next;
            temp->next = dnode->next;
            dnode->next = NULL;
            delete dnode;

        }

        return head;
        
    }
};