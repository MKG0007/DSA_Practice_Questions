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
    TreeNode* construct(int preStart, int preEnd, int postStart, vector<int> &preorder, vector<int> &postorder){
        if(preStart > preEnd)
            return nullptr;
        if(preStart == preEnd)
            return new TreeNode(preorder[preStart]);
        TreeNode *root = new TreeNode(preorder[preStart]);
        int left = preorder[preStart+1], noOfElementsOnLeft = 1;
        while(postorder[postStart + noOfElementsOnLeft - 1]!=left)
            noOfElementsOnLeft++;
        root->left = construct(preStart+1, preStart + noOfElementsOnLeft, postStart, preorder, postorder);
        root->right = construct(preStart+1+noOfElementsOnLeft, preEnd, postStart+noOfElementsOnLeft, preorder, postorder);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return construct(0, n-1, 0, preorder, postorder);
    }
};