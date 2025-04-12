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

    int findMaxPath(TreeNode* root , int &maxPath){
        if(root == NULL) return 0;

        int leftSum = max(0 , findMaxPath(root -> left , maxPath));
        int rightSum = max(0 , findMaxPath(root -> right , maxPath));


        maxPath = max(maxPath , (root->val + leftSum + rightSum));

        return root->val + max(leftSum , rightSum);
    }
    int maxPathSum(TreeNode* root) {

        int mPath = INT_MIN;

        findMaxPath(root , mPath);
        return mPath;
        
    }
};