/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* workFlatten(Node* head){
        if(head == NULL) return head;
        Node* temp = head;

        while(temp != NULL){
            if(temp->child != NULL){
                Node* tNext = temp->next;
                temp->next = workFlatten(temp->child);
                temp->next->prev = temp;
                temp->child = NULL;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                if(tNext != NULL){
                    temp->next = tNext;
                    tNext->prev = temp;
                }
            }
            temp = temp->next;
        }
        return head;
    }
    Node* flatten(Node* head) {

        return workFlatten(head);


        
    }
};