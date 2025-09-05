/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
         int count[3] = {0, 0, 0};
        Node* temp = head;
        while (temp != nullptr) {
            
            
            count[temp->data]++;
            temp = temp->next;
        }

        
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            if (count[i] == 0) {
                i++;
            } else {
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }

        return head;

    
        
    }
};