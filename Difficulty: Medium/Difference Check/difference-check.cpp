class Solution {
  public:
    int minDifference(vector<string> &arr) {
        
        vector<int>op;
        
        for(auto it:arr){
            int hr=3600*stoi(it.substr(0,2));
            int mint=60*stoi(it.substr(3,2));
            
            int sec=1*stoi(it.substr(6,2));
            
            
            int tot=hr+mint;
            tot+=sec;
            tot=tot%86400;
            op.push_back(tot);
        }
        sort(op.begin(),op.end());
        
        int n=arr.size();
        int ans=INT_MAX;
        
        for(int i=1;i<n;i++){
            ans=min(ans,(op[i]-op[i-1]));
        }
        
         ans = min(ans, (86400 + op[0] - op[n - 1]) % 86400);
        
        return ans;
        
    }
};