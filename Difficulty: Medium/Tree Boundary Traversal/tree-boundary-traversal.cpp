class Solution {
  public:
  
  bool isLeaf(Node* root){
      return root->left == NULL && root->right == NULL;
  }

  void addLeftBoundary(Node* root , vector<int> &res){
      Node* curr = root->left;
      while(curr){
          if(!isLeaf(curr)) res.push_back(curr->data);
          if(curr->left) curr = curr->left;
          else curr = curr->right;
      }
  }

  void addLeaves(Node* root , vector<int> &res){
      if(root == NULL) return;
      if(isLeaf(root)) {
          res.push_back(root->data);
          return;
      }
      addLeaves(root->left, res);
      addLeaves(root->right, res);
  }

  void addRightBoundary(Node* root , vector<int> &res){
      Node* curr = root->right;
      stack<int> st;
      while(curr){
          if(!isLeaf(curr)) st.push(curr->data);
          if(curr->right) curr = curr->right;
          else curr = curr->left;
      }
      while(!st.empty()){
          res.push_back(st.top());
          st.pop();
      }
  }

  vector<int> boundaryTraversal(Node *root) {
      vector<int> res;
      if(root == NULL) return res;
      if(!isLeaf(root)) res.push_back(root->data);

      addLeftBoundary(root, res);
      addLeaves(root, res);
      addRightBoundary(root, res);

      return res;
  }
};
