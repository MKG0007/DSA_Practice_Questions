/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        if(head == NULL) return 0;
        
        int len = 0;
        
        Node* temp = head;
        
        while(temp){
            temp = temp->next;
            len++;
        }
        
        temp = head;
        for(int i = 0 ; i<len/2 ; i++){
            temp = temp->next;
        }
        
        return temp->data;
        // code here
        
    }
};