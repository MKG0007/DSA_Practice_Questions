class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
    
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        vector<int>ans;
        stack<pair<int,int>>s;
        for(int i=arr.size()-1;i>=0;i--){
            while(!s.empty() && s.top().second<=m[arr[i]])
            s.pop();
            if(!s.empty())
            ans.push_back(s.top().first);
            else
            ans.push_back(-1);
            s.push({arr[i],m[arr[i]]});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};