/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
    // base case
    if(head == NULL) return head;
        
    Node* curr= head, *prev = NULL;
    Node* next = curr->next;
    int cnt =0;


    while(curr != NULL && cnt < k )
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if(next!= NULL)
    head->next = reverseKGroup(next, k); 
    return prev;
    }
};