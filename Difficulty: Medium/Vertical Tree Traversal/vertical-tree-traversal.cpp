/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/



class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        map<int, vector<int>> mp; // col -> list of nodes in BFS order
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int col = it.second;

            mp[col].push_back(node->data); // preserve BFS order

            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }

        for (auto &p : mp)
            ans.push_back(p.second);

        return ans;
    }
};
