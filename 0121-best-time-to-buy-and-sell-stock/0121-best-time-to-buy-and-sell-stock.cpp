class Solution {
public:
    int maxProfit(vector<int>& p) {
        int size = p.size();
        int bmax = p[0];
        int ans = INT_MIN;

        for(int i = 1 ; i<size ; i++){
            ans = max(ans , p[i]-bmax);
            bmax = min(bmax , p[i]);
        }
        if(ans<0){
            return 0;
        }
        return ans;
        
    }
};