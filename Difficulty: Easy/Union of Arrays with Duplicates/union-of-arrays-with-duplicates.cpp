class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> s;
        vector<int> ans;
        
        for(int ele : a){
            s.insert(ele);
        }
        
        for(int ele : b){
            s.insert(ele);
        }
        
        for(auto ele : s){
            ans.push_back(ele);
        }
        
        return ans;
    }
};