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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        unordered_map<int , int> m;
        queue<pair<TreeNode* , int>> q;
        q.push({root , 1});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(m.find(node.second) != m.end()){
                m[node.second] += node.first->val;
            }
            else m[node.second] = node.first->val;
            if(node.first->left) q.push({node.first->left , node.second+1});
            if(node.first->right) q.push({node.first->right , node.second+1});
        }
        int maxsum = INT_MIN;
        int ans = 0;
        for(auto ele : m){
            if(ele.second > maxsum){
                maxsum = ele.second;
                ans = ele.first;
            }
        }

        return ans;

        
    }
};