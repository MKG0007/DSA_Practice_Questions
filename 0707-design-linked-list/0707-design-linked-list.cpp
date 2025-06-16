
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
    Node* head ;
    Node* tail ;
    int size;
    MyLinkedList() {

        head = tail = NULL;
        size = 0;
        
    }
    
    int get(int index) {
        if(index<0 || index>=size){return -1;}
        Node* temp = head;
        for(int i = 0 ;i<index; i++){
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
        if(head == NULL){
            addAtHead(val);
        }
        else{
            Node* newNode = new Node(val);
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return ;
        if(index == size){
            addAtTail(val);
            return ;
        }
        else if(index == 0){
            addAtHead(val);
            return ;
        }
        else{
            Node* newNode = new Node(val);
            Node* temp = head;

            for(int i = 0 ; i<index-1 ; i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
        
    }
    
    void deleteAtIndex(int index) {
        
        if(index <0 || index>=size ) return ;
        Node* temp = head;
        if(index == 0){
            head = temp->next;
            temp->next = NULL;
            delete temp;
            size--;
            if(size == 0) tail = NULL;
            return;
        }
        else{
            for(int i = 0 ; i<index-1 ; i++){
                temp = temp->next;
            }
            Node* dtemp = temp->next;
            temp->next = temp->next->next;
            if(index == size-1) tail = temp;
            dtemp->next = NULL;
            delete dtemp;
            size--;

        }

        
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