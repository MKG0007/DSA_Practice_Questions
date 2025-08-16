/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        stack<int> st;
        
        DLLNode* temp = head;
        
        while(temp){
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(!st.empty()){
            temp->data = st.top();
            temp = temp->next;
            st.pop();
        }
        
        return head;
    }
};