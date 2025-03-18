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
    void maxLength(TreeNode* root , int count , int &maxCount){
        if (root == NULL) {
            maxCount = max(count , maxCount);
            return;
        }

        count++;
        maxLength(root->left , count , maxCount);
        maxLength(root->right , count , maxCount);
        count--;
    }
    int maxDepth(TreeNode* root) {
        int ans = 0;

        maxLength(root , 0 , ans);
        return ans;
    }
};