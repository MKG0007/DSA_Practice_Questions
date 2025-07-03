//Position this line where user code will be pasted.
class Solution {
  public:
    void dfso(vector<vector<int>> &adj , vector<int> &vis , stack<int> &st , int node){
        
        vis[node] = 1;
        
        for(auto ele : adj[node]){
            if(!vis[ele]){
                dfso(adj , vis , st , ele);
            }
        }
        
        st.push(node);
    }
    void dfsn(unordered_map<int , vector<int>> &ad , vector<int> &vis , int node){
        
        vis[node] = 1;
        
        for(auto ele : ad[node]){
            if(!vis[ele]){
                dfsn(ad , vis , ele);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        unordered_map<int , vector<int>> ad;
        int row  = adj.size();
        int col = adj[0].size();
        vector<int> vis1(row , 0);
        vector<int> vis2(row , 0);
        stack<int> st;
        
        for(int i = 0 ; i<row ; i++){
            if(!vis1[i]){
                dfso(adj , vis1 , st , i);
            }
        }
        
        for(int i = 0 ; i<row ; i++){
            for(auto ele : adj[i]){
                ad[ele].push_back(i);
            }
        }
        
        int count = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis2[node]){
                dfsn(ad , vis2 , node);
                count++;
            }
        }
        
        return count;
        
    }
};