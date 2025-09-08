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
    Node* mergeSort(Node* head) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        Node* curr = head;
        
        while(curr) {
            pq.push(curr->data);
            curr = curr->next;
        }
        Node* ans = new Node(-1);
        curr = ans;
        
        while(!pq.empty()) {
            curr->next = new Node(pq.top());
            pq.pop();
            curr = curr->next;
        }
        
        return ans->next;
    }
};