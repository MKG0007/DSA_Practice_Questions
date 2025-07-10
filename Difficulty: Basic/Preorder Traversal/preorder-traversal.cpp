/* A binary tree node has data, pointer to left child
   and a pointer to right child

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:

    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        
        st.push(root);
        
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            ans.push_back(node->data);
            
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            
        }
        
        return ans;
    }
};