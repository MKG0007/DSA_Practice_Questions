/* A binary tree node structure

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
  
  int check(Node* root){
      if(root == NULL) return 0;
      
      int l = check(root->left);
      if(l == -1) return -1;
      
      int r = check(root->right);
      if(r == -1) return -1;
      if(abs(l-r) > 1) return -1;
      
      return 1+max(l , r);
  }
    bool isBalanced(Node* root) {
    
        if(check(root) == -1) return false;
        
        return true;
    }
};