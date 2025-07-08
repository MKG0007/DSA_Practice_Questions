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
      int calculate(Node* root){
        if(root == NULL) return 0;
        
        int l = calculate(root->left);
        int r = calculate(root->right);
        
        return 1+ max(l , r);
    }
  bool check(Node* root){
      if(root == NULL) return true;
      
      int l = calculate(root->left);
      int r = calculate(root->right);
      if(abs(l-r)>1) return false;
      
      bool lh = check(root->left );
      bool rh = check(root->right);
      
      if(lh == false || rh == false) return false;
      
      return true;
      
  }
    bool isBalanced(Node* root) {
        
        
        return check(root);
        
    }
};