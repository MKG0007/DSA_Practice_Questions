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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            
            vector<int> temp(size , 0);
            
            for(int i = 0 ; i<size ; i++){
                Node* node = q.front();
                q.pop();
                
                int index = 0;
                (flag)? index = i : index = size-i-1;
                temp[index] = node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag) flag = false;
            else flag = true;
            for(int ele : temp){
                ans.push_back(ele);
            }
        }
        
        return ans;
    }
};