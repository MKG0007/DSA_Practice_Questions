/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(head == NULL) return head;
        
        Node* temp = head ;
        int size = 0;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        
        if(x<0 || x>size) return temp;
        
        Node* del = NULL;
        if(x == 1){
            del = head;
            head = head->next;
            
        }
        else if(size == x){
            temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            
            del = temp->next;
            temp->next = NULL;
        }
        else{
            temp = head ;
            for(int i = 1 ; i<=x-2 ; i++){
                temp  = temp->next;
            }
            
            del = temp->next;
            temp->next = del->next;
            del->next = NULL;
        }
        
        delete del;
        return head;
        
    }
};