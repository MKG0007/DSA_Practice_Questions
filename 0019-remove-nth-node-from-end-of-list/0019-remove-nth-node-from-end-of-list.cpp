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
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        if(size < n || n<0) return head;
        else if(size == n){
            ListNode* dnode = head;
            head = dnode->next;
            dnode->next = NULL;
            delete dnode;
        }
        else{
            int pos = size-n;
            temp = head;
            for(int i = 1 ; i<pos ; i++){
                temp = temp->next;
            }

            ListNode* dnode = temp->next;
            temp->next = dnode->next;
            delete dnode;
        }

        return head;

        
    }
};