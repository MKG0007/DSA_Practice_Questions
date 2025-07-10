/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            vector<int> temp;
            
            for(int i = 0 ; i<size ; i++){
                Node* node = q.front();
                q.pop();
                temp.push_back(node->data);
                
                if( node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};