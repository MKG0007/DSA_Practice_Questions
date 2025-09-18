class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int size = arr.size();

        int maxi = 0;
        int num = arr[0];
        for(int i = 1 ; i<size ; i++){
            maxi = max(maxi , arr[i]-num);

            num = min(num , arr[i]);

        }


        return maxi;

    }
};