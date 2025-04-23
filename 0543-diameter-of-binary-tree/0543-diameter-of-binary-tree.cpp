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

    int findTheDaimeter(TreeNode* root , int &daimeter){
        if(root == NULL) return 0;

        int lh = findTheDaimeter(root->left , daimeter);
        int rh = findTheDaimeter(root->right , daimeter);

        daimeter = max(daimeter , lh+rh);

        return 1+ max(lh , rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        int daimeter = INT_MIN;

        findTheDaimeter(root , daimeter);
        return daimeter;
        
    }
};