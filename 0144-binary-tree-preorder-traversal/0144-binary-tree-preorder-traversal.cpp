/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.top();
            ans.push_back(temp->val);
            q.pop();
            if(temp->right != NULL){
                q.push(temp->right);
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
        }

        return ans;
        
    }
};