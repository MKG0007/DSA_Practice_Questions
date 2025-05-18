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

    ListNode* reverseList(ListNode* head){
        if(head->next == NULL){
            return head;
        }
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    int pairSum(ListNode* head) {
        if(head == NULL){
            return -1;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

        }

        slow->next = reverseList(slow->next);
        ListNode* temp1 = head;
        ListNode* temp2 = slow->next;
        int maxSum = 0;
        while(temp2 != NULL){
            maxSum = max(maxSum , temp1->val + temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return maxSum;


        
    }
};