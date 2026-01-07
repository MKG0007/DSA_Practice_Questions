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
    int mode = 1e9 + 7;
    void preOrder(TreeNode* root , long long &totalSum) {
        if (!root) return;
        totalSum += root->val;
        preOrder(root->left , totalSum);
        preOrder(root->right , totalSum);
    }

    
    long long helper(TreeNode* root , long long totalSum , long long &ans) {
        if (!root) return 0;

        long long left = helper(root->left, totalSum , ans);
        long long right = helper(root->right, totalSum , ans);

        long long currSum = left + right + root->val;

        ans = max(ans, currSum * (totalSum - currSum));

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        long long ans = 0;
        long long totalSum = 0;
        preOrder(root , totalSum);// total sum
        helper(root , totalSum , ans);        
        return ans % mode;
    }
};
