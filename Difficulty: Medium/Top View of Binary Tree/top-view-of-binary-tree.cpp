/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        queue<pair<Node* , int>> q;
        map<int , int> m;
        q.push({root , 0});
        
        while(!q.empty()){
            Node* node = q.front().first;
            int ver = q.front().second;
            q.pop();
            if(m.find(ver) == m.end()){
                m[ver] = node->data;
            }
            
            if(node->left) q.push({node->left , ver+(-1)});
            if(node->right) q.push({node->right , ver+1});
            
        }
        vector<int> ans;
        for(auto ele : m){
            ans.push_back(ele.second);
        }
        
        return ans;
    }
};