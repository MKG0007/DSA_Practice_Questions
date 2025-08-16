class Solution {
  public:
    Node *addNode(Node *head, int p, int x) {
        Node* temp = head;
        Node* newNode = new Node(x);

        int len = 0;
        while (temp) {
            temp = temp->next;
            len++;
        }

        // invalid position
        if (p >= len || p < 0) return head;

        temp = head;

        // traverse to node at position p
        for (int i = 0; i < p; i++) {
            temp = temp->next;
        }

        // insert after temp
        newNode->next = temp->next;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        newNode->prev = temp;
        temp->next = newNode;

        return head;
    }
};
