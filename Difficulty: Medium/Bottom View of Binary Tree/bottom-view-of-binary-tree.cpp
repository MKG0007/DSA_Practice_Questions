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
        
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        
        map<int , int> m;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            m[node.second] = node.first->data;
            
            if(node.first->left) q.push({node.first->left , node.second-1});
            if(node.first->right) q.push({node.first->right , node.second+1});
        }
        
        for(auto ele : m){
            ans.push_back(ele.second);
            
        }
        
        return ans;
        
    }
};