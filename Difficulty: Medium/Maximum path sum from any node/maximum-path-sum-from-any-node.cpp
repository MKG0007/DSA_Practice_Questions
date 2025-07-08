// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    
    int pathSum(Node* root , int &maxi){
        if(root == NULL) return 0;
        
        int leftSum = max(0 , pathSum(root->left , maxi));
        int rightSum = max ( 0 , pathSum(root->right , maxi));
        
        maxi = max(maxi , (root->data)+leftSum + rightSum);
        
        return (root->data) + max(leftSum , rightSum);
    }
    int findMaxSum(Node *root) {
        
        int maxi = INT_MIN;
        
        pathSum(root , maxi);
        
        
        return maxi;
        
        
        
        
        
        
        
        
    }
};