/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
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
    int height(Node* node) {
        if(node == NULL) return 0;
        
        return calculate(node)-1;
        
    }
};