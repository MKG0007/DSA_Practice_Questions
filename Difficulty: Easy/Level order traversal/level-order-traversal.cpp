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
        
        
        queue<Node*> q;
        vector<vector<int>> ans;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> a;
            for(int i = 0 ; i<size ; i++){
                Node* n = q.front();
                if(n->left != NULL) q.push(n->left);
                if(n->right != NULL) q.push(n->right);
                a.push_back(n->data);
                q.pop();
            }
            ans.push_back(a);
        }
        return ans;
    }
};