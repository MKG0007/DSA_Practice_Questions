class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        
        int n=arr.size();
        int tsum=accumulate(arr.begin(),arr.end(),0);
        
        vector<int>dp(n,1);
        vector<int>par(n,-1);
        
        
        vector<int>prevSum(n,0);
        for(int i=0;i<n;i++) prevSum[i]=arr[i];
        int num=0;
        int ucidx=-1;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    
                    
                    if(dp[j]+1>dp[i] || dp[j]+1==dp[i] && prevSum[j]+arr[i]<prevSum[i]){
                        dp[i]=dp[j]+1;
                        prevSum[i]=prevSum[j]+arr[i];
                        par[i]=j;
                    }
                    
                }
                
            }
            if(dp[i]>maxi){
                ucidx=i;
                maxi=dp[i];
                num=prevSum[i];
            }
            else if(dp[i]==maxi && prevSum[i]<num){
                ucidx=i;
                num=prevSum[i];
            }
            
        }
        return tsum-prevSum[ucidx];
    }
};

