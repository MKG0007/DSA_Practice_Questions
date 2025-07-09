/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool check(Node* root1 , Node* root2){
        if(root1 == NULL || root2 == NULL) return root1 == root2;
        if(root1->data != root2->data) return false;
        if(check(root1->left , root2->right) == false) return false;
        if(check(root1->right , root2->left) == false) return false;
        return true;
    } 
    bool isSymmetric(Node* root) {
        
        return check(root , root);
        
    }
};