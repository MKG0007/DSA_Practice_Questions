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
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow->next != NULL){
        slow->next = reverseList(slow->next);
        }

        ListNode* temp1 = head;
        ListNode* temp2 = slow;
        if(slow->next != NULL){
            temp2 = slow->next;
        }

        while(temp2 != NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
        
    }
};