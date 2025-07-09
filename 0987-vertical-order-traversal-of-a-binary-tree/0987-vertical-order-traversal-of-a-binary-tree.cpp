class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;//verticall , level , {ele}
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            TreeNode* node = ele.first;
            int x = ele.second.first;  // vertical
            int y = ele.second.second; // level

            nodes[x][y].insert(node->val);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> result;

        for (auto ele : nodes) {
            vector<int> temp;
            for (auto col : ele.second) {
                temp.insert(temp.end(), col.second.begin(), col.second.end());
            }
            result.push_back(temp);
        }

        return result;
    }
};
