/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if(head == NULL || head->next == NULL) return 0;
        
        Node* slow = head;
        Node* fast = head;
        
        int isCheck = 1;
        while(fast && fast->next){
            slow = slow ->next;
            fast = fast->next->next;
            if(fast == slow){
                isCheck = 0;
                break;
            }
        }
        
        if(isCheck){
            return 0;
        }
        
        slow = head;
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        int len = 1;
        fast= fast->next;
        while(slow != fast){
            fast = fast->next;
            len++;
        }
        
        return len;
        
    }
};