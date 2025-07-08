/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    
    int leftToRight = 1;
    vector<int> zigZagTraversal(Node* root) {
        
        vector<int> ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size , 0);
            for(int i = 0 ;i<size ; i++){
                Node* node = q.front();
                q.pop();
                
               int index =  (leftToRight)?  i : size-i-1;
               temp[index] = node->data;
               
               if(node -> left != NULL) q.push(node->left);
               if(node -> right != NULL) q.push(node->right);
            }
            leftToRight = !leftToRight;
            for(int ele : temp) ans.push_back(ele);
            
        }
        return ans;
        
    }
};