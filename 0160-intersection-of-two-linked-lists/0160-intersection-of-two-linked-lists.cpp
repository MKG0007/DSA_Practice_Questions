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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL) return headA;
        if(headB == NULL) return headB;
        
        int size1 = 0;
        int size2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1 != NULL){
            temp1 = temp1->next;
            size1++;
        }
        while(temp2 != NULL){
            temp2 = temp2->next;
            size2++;
        }
        temp1 = headA;
        temp2 = headB;
        int steps = abs(size1-size2);
        if(size1<size2){
            
            for(int i = 1 ; i<=steps ; i++){
                temp2 = temp2->next;
            }
        }
        else{
            
            for(int i = 1 ; i<=steps ; i++){
                temp1 = temp1->next;
            }
        }
        
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return temp1;
    }
};