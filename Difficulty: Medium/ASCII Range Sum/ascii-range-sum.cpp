class Solution {
  public:
    vector<int> asciirange(string& s) {
        
        int n=s.size();
        vector<int> preffix(n,0);
        unordered_map<int,vector<int>> store;
        
        preffix[0]=(int)s[0];
        store[s[0]-'a'].push_back(0);
        
        
        for(int i=1;i<n;i++){
            preffix[i]=preffix[i-1]+(int)s[i];
            
            store[s[i]-'a'].push_back(i);
        }
        
        vector<int> result;
        for(auto it:store){
            
            int key=it.first;
            vector<int> val=it.second;
            if(val.size()>1 && val.back()-1>val[0]) result.push_back(preffix[val.back()-1]-preffix[val[0]]);
        }
        return result;
    }
};