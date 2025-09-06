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
        if(head == NULL) return 0;
        // code here
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(fast== NULL || fast->next == NULL) return 0;
        int len = 1;
        slow = slow->next;
        while(slow != fast){
            slow = slow->next;
            len++;
        }
        
        return len;
    }
};