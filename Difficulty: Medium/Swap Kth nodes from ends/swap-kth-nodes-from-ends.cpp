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
    Node* swapKth(Node* head, int k) {
        if(head == NULL) return head;
        int len = 1;
        Node* temp = head;
        
        while(temp){
            temp = temp->next;
            len++;
        }
        
        if(k<=len){
            temp = head;
            Node* tp = head;
            for(int i = 1 ; i<k ; i++){
                tp = tp->next;
            }
            int p = len-k;
            for(int i = 1 ; i<p ; i++){
                temp = temp->next;
            }
            swap(tp->data , temp->data);
        }
        
        
        return head;
        
    }
};