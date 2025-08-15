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
    int getCount(Node* head) {
        // Code here
        int size = 0;
        Node* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }
};