/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        stack<Node*> st;
        Node* temp = root;
        vector<int> ans;
        
        while(true){
            if(temp != NULL){
                st.push(temp);
                temp = temp->left;
            }
            else{
                if(st.empty()) break;
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                temp = temp->right;
            }
        }
        return ans;
    }
};