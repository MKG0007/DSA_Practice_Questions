class Solution {
  public:
    int maxScore(vector<int>& cp, int k) {
        int size = cp.size();
        int sum = 0;
        for(int i = 0 ; i<k ; i++){
            sum += cp[i];
        }

        int ans = sum;
        int r = size-1;
        for(int i = k-1 ; i>=0 ; i--){
            sum -= cp[i];
            sum += cp[r];
            ans = max(ans , sum);
            r--;
        }

        return ans;
    }
};
