/*

Definition for Binary Tree Node
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
    void findpaths(Node* root, vector<int> &temp, vector<vector<int>> &ans) {
        if (!root) return;

        temp.push_back(root->data); // Step 1: include current node

        // Step 2: if it's a leaf, store the current path
        if (!root->left && !root->right) {
            ans.push_back(temp);
        } else {
            // Step 3: explore left and right children
            findpaths(root->left, temp, ans);
            findpaths(root->right, temp, ans);
        }

        temp.pop_back(); // Step 4: backtrack
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> temp;
        // temp.push_back(root->data);
        
        findpaths(root , temp , ans);
        
        return ans;
        
    }
};