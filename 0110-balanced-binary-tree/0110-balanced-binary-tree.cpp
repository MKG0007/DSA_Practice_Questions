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

    int checkTheBalancedTree(TreeNode* node){
        if(node == NULL){
            return 0;
        }

        int sl = checkTheBalancedTree(node->left);
        if(sl == -1) return -1;
        int sr = checkTheBalancedTree(node->right);
        if(sr == -1) return -1;

        if(abs(sl - sr)>1) return -1;

        return 1 + max(sl , sr);
    }
    bool isBalanced(TreeNode* root) {

        if(checkTheBalancedTree(root) != -1){
            return true;
        }

        return false;

        
        
    }
};