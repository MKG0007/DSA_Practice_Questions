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
    void inOrder(Node* root , vector<int>&ans){
        if(root == NULL){
            return ;
        }
        
        inOrder(root->left , ans);
        ans.push_back(root->data);
        inOrder(root->right , ans);
    }
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        inOrder(root , ans);
        return ans;
        
    }
};