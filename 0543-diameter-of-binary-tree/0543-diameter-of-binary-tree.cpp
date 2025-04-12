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
    //broot force
    int findDiameter(TreeNode* root , int &dSize){
        if(root == NULL){
            return 0;
        }

        int leftHeight = findDiameter(root->left , dSize);
        int rightHeight = findDiameter(root->right , dSize);

        dSize = max(dSize , leftHeight + rightHeight);
        return 1+ max(leftHeight , rightHeight);

    }



    int diameterOfBinaryTree(TreeNode* root) {
        int dLength = 0;

        findDiameter(root , dLength);

        return dLength;

        
    }
};