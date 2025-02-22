
class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
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
        if (index < 0 || index >= size) return -1; // Fix index bounds check
        
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;  
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return; // Fix invalid index check
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return; // Fix invalid index check
        
        Node* temp = head;
        
        // Case: Delete head
        if (index == 0) {
            head = head->next;
            delete temp;
            size--;
            if (size == 0) tail = NULL; // If list becomes empty, reset tail
            return;
        }

        // Traverse to the node before the one to be deleted
        Node* prev = NULL;
        for (int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }
        
        prev->next = temp->next;

        // If deleting the last node, update tail
        if (index == size - 1) {
            tail = prev;
        }
        
        delete temp;
        size--;
    }

    void printList() { // Utility function for debugging
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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