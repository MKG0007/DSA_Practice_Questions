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
    Node* flatten(Node* head) {
        if(head == NULL) return head;


        Node* crr = head;

        while(crr != NULL){
            if(crr->child != NULL){
                //flatten the child node
                Node* next = crr->next;
                crr->next = flatten(crr->child);
                crr->next->prev = crr;
                crr->child = NULL;

                //find tail
                while(crr->next != NULL){
                    crr = crr->next;
                }

                //attach tail with next ptr
                if(next != NULL){
                    crr->next = next;
                    next->prev = crr;

                }

            }
            crr = crr->next;
        }
        return head;
    }
};