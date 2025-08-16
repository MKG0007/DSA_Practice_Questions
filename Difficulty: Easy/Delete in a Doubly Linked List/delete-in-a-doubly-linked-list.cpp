/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        if(head == NULL) return head;
        Node* temp = head;
        Node* del = NULL;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        temp = head;
        
        if(x<=0 || x>len) return head;
        
        if(x == 1){
            del = head;
            head = head->next;
            if(head){
                head->prev = NULL;
            }
            del->next = NULL;
        }
        else{
            for(int i = 1 ; i<x ; i++){
                temp = temp->next;
            }
            
            del = temp;
            if(del->prev) del->prev->next = del->next;
            if(del->next) del->next->prev = del->prev;
        }
        
        delete del;
        
        return head;
        
    }
};