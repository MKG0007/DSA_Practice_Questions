/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<Node*> st1;
        stack<int> st2;
        
        st1.push(root);
        
        while(!st1.empty()){
            Node* node = st1.top();
            st2.push(node->data);
            st1.pop();
            
            if(node->left != NULL) st1.push(node->left);
            if(node->right != NULL) st1.push(node->right);
        }
        
        while(!st2.empty()){
            int node = st2.top();
            ans.push_back(node);
            st2.pop();
        }
        return ans;
        
    }
};