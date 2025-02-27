class Solution {
public:
    unordered_map<int ,int> mp;
    vector<vector<int>> dp;
    int solve(vector<int>& arr,int i,int j)
    {
        if(mp.find(arr[i]+arr[j])==mp.end())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=1+solve(arr,j,mp[arr[i]+arr[j]]);
    }
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        int n=arr.size();
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n-ans+1;i++)
        {
            for(int j=i+1;j<n-ans+1;j++)
            {
                int mx=2+solve(arr,i,j);
                ans=max(ans,mx);
            }
        }
        return ans<3?0:ans;
    }
};