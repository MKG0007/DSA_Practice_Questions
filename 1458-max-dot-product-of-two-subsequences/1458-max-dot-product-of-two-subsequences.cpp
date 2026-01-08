class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, INT_MIN));
        int res=INT_MIN;
        
        function<int(int, int)> f=[&](int i, int j)->int{
            if (i==n1 || j==n2) return INT_MIN;
            if (dp[i][j]!=INT_MIN) return dp[i][j];
            int x=nums1[i]*nums2[j];
            int ans=max({
                x,
                x+(i+1<n1 & j+1<n2 ? f(i+1, j+1):0),
                f(i, j+1),
                f(i+1, j),
            
            });
            res=max(res, ans);
            return dp[i][j]=ans;
        };

        f(0, 0);
        return res;
    }
};