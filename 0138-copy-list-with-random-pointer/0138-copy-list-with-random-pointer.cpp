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
        unordered_map<Node* , Node*>m;
        Node* nhead = NULL;
        Node* tail = NULL;

        Node* temp = head;

        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            if(nhead == NULL){
                nhead = tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            m[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        Node* ntemp = nhead;

        while(temp != NULL && ntemp != NULL){
            if(m.find(temp->random) == m.end()){
                ntemp->random = NULL;
            }
            else{
            ntemp->random = m[temp->random];
            }
            temp = temp->next;
            ntemp = ntemp->next;

        }


        return nhead;
    }
};