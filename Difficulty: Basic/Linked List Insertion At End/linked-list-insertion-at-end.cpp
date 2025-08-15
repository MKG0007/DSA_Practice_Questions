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
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            
            while(temp->next != NULL){
                temp = temp->next;
            }
            
            temp->next = newNode;
        }
        
        return head;
    }
};