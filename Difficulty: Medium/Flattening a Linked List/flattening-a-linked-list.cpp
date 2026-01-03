class Solution {
  public:
    Node *flatten(Node *root) {
        if (!root) return root;

        vector<int> store;
        Node* temp = root;

        
        while (temp) {
            Node* curr = temp;
            while (curr) {
                store.push_back(curr->data);
                curr = curr->bottom;
            }
            temp = temp->next;
        }

        
        sort(store.begin(), store.end());

    
        temp = root;
        Node* curr = temp;

        curr->data = store[0];
        curr->next = NULL;

        for (int i = 1; i < store.size(); i++) {
            curr->bottom = new Node(store[i]);
            curr = curr->bottom;
        }

        return temp;
    }
};
