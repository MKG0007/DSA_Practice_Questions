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
  
  bool isleaf(Node* root){
      if(!root->left && !root->right){
          return true;
      }
      
      return false;
  }
  
  void leftt(Node* root , vector<int> &ans){
      Node* crr = root->left;
      
      while(crr){
          if(!isleaf(crr)) ans.push_back(crr->data);
          if(crr->left) crr = crr->left;
          else crr = crr->right;
      }
      
      
      
  }
  
  void rightt(Node* root , vector<int> &ans){
      Node* crr = root->right;
      stack<int> q;
      while(crr){
          if(!isleaf(crr)) q.push(crr->data);
          if(crr->right) crr = crr->right;
          else crr = crr->left;
      }
      
      while(!q.empty()){
          ans.push_back(q.top());
          q.pop();
      }
      
  }
  
  void leaff(Node* root , vector<int> &ans){
      if(root == NULL) return ;
      
      if(isleaf(root)) ans.push_back(root->data);
      
      leaff(root->left , ans);
      leaff(root->right , ans);
      
      
  }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        if(!isleaf(root)) ans.push_back(root->data);
        
        leftt(root , ans);
        leaff(root , ans);
        rightt(root , ans);
        
        
        return ans;
        
        
    }
};