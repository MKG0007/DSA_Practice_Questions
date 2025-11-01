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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head || nums.size() == 0) return head;

        unordered_set<int> m;
        for(int ele : nums) m.insert(ele);

        ListNode* newhead = new ListNode(-1);
        ListNode* crr = newhead;
        ListNode* temp = head;

        while(temp){

            if(m.find(temp->val) == m.end()){

                ListNode* newNode = new ListNode(temp->val);
                crr->next = newNode;
                crr = newNode;

            }
            temp = temp->next;
        }

        return newhead->next;

    //     ListNode* temp = head;
    //     ListNode * prev = head;
    //     while(temp){
    //         if(m.find(temp->val) != m.end()){
    //             if(temp->next){
    //                 if(prev){
    //                     prev->next = temp->next; 
    //                 }
    //                 else{

    //                     prev = temp->next;
    //                 }
    //             }
    //             else{
    //                 prev->next = nullptr;
    //             }
    //         }
    //         prev = temp;
    //         temp = temp->next;
    //     }

    //     return head;
    }
};