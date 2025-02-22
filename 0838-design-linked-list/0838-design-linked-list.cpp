
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = tail = NULL;   
        size = 0;
    }
    
    int get(int index) {
        if(index<0 || index>size){
            return -1;
        }
        Node* temp = head;
        for(int i = 0 ; i<index ; i++){
            temp = temp->next;
        }
        return temp->data;
        
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        size++;  
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
        }
        else if(index<0 || index>size){
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i = 0 ; i<index-1 ; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(head == NULL || index <0 || index>=size){
            return;
        }

        Node* temp = head;
        for(int i = 0 ; i<index-1 ; i++){
            temp = temp->next;
        }
        Node* dnode = temp ->next;
        if(dnode->next == NULL){
            temp->next = NULL;
        }
        else{
            temp->next = dnode->next;
            dnode->next = NULL;
        } 
        delete dnode;
        size--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */