/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    void leftv(Node* root , vector<int> &ans , int level){
        if(root == NULL) return ;
        if(level == ans.size()){
            ans.push_back(root->data);
        }
            leftv(root->left , ans , level+1);
            leftv(root->right , ans , level+1);
        
    }
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        leftv(root , ans , 0);
        
        return ans;
        
    }
};