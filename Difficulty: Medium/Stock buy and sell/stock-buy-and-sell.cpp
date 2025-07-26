class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        unordered_map<int , int> m;
        int size = arr.size();
        
        int max_profit = 0;
        int buy_time = arr[0];
        for(int i = 1 ; i<size ; i++){
            int profit = arr[i]-buy_time;
            if(profit>0){
                max_profit += profit;
                if(m[buy_time]+1<size){
                buy_time = arr[m[buy_time]+1];
                }
            }
            buy_time = min(buy_time , arr[i]);
            m[arr[i]] = i;
        }
        
        return max_profit;
    }
};