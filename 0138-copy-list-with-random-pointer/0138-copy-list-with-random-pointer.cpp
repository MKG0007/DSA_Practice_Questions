/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* newhead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        unordered_map<Node* , Node*> m;
        m[head] = newtemp;
    
        while(oldtemp != NULL){
            Node* newNode = new Node(oldtemp->val);
            m[oldtemp] = newNode;
            newtemp->next = newNode;
            newtemp = newtemp->next;
            oldtemp = oldtemp->next;

        }
        newtemp = newhead;
        oldtemp = head;

        while(oldtemp != NULL){
            newtemp->random = m[oldtemp->random];
            newtemp = newtemp->next;
            oldtemp = oldtemp->next;
        }

        return newhead;


        
    }
};