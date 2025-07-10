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
  int height(Node* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        
        queue<Node*> q;
        q.push(root);
        int height = -1;
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0 ; i<size ; i++){
                Node* node = q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            height++;
        }
        
        return height;
  }
};