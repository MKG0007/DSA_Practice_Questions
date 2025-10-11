/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
  bool check(Node* root1 , Node* root2){
      if(root1 == nullptr || root2 == nullptr) return root1 == root2;
      
      if(root1->data != root2->data) return false;
      if(!check(root1->left , root2->left)) return false;
      if(!check(root1->right , root2->right)) return false;
      
      return true;
  }
    bool isIdentical(Node* r1, Node* r2) {
        
        return check(r1 , r2);
        
    }
};