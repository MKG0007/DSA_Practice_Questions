/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
  int findD(Node* root , int &maxii){
      if(root == NULL) return 0;
      
      int l = findD(root->left , maxii);
      int r = findD(root->right , maxii);
      
      maxii = max(maxii , l+r);
      
      return 1+max(l , r);
  }
    int diameter(Node* root) {
        int maxi = 0;
        findD(root , maxi);
        
        return maxi;
        
    }
};