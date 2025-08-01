class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
  
        int n=mat.size();
        int count1=0,count2=0;
        int maxRowSum=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
                
            }
            maxRowSum=max(maxRowSum,sum);
        }
        int maxColSum=0;
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                
                sum+=mat[i][j];
            }
            maxColSum=max(maxColSum,sum);
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
            }
            count1+=maxRowSum-sum;
        }
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=mat[i][j];
            }
            count2+=maxColSum-sum;
        }
        return max(count1,count2);
    }
}
;