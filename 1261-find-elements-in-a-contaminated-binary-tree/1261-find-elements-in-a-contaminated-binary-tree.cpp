// class TreeNode {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
    
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class FindElements {
private:
    std::unordered_set<int> recoveredValues;

    void recoverTree(TreeNode* node, int value) {
        if (node == nullptr) {
            return;
        }
        node->val = value;
        recoveredValues.insert(value);
        recoverTree(node->left, 2 * value + 1); // Recover left child
        recoverTree(node->right, 2 * value + 2); // Recover right child
    }

public:
    FindElements(TreeNode* root) {
        recoverTree(root, 0);
    }

    bool find(int target) {
        return recoveredValues.find(target) != recoveredValues.end();
    }
};