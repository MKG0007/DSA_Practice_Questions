/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int , int> m;
        
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            Node* ele = node.first;
            int dec = node.second;
            m[dec] = ele->data;
            
            if(ele->left != NULL) q.push({ele->left , dec-1});
            if(ele->right != NULL) q.push({ele->right , dec+1});
        }
        // code here
        for(auto ele : m){
            ans.push_back(ele.second);
        }
        
        return ans;
        
    }
};