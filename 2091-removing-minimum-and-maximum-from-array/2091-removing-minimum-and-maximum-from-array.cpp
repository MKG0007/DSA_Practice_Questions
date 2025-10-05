class Solution {
public:
    int minimumDeletions(vector<int>& arr) {
        int size = arr.size();
        if(size == 0) return 0;
        if(size == 1) return 1;

        int large = INT_MIN;
        int small = INT_MAX;
        int ii = 0;
        int j = 0;

        for(int i = 0 ; i<size ; i++){
            if(large<arr[i]){
                large = arr[i];
                ii = i;
            }
            if(small>arr[i]){
                small = arr[i];
                j = i;
            }
        }

        int ans1 = max(ii , j)+1;

        int ans2 = size - min(ii , j);

        int ans3 = min(ii , j)+1 + size-(max(ii , j));

        return min(ans1 , min(ans2 , ans3));



        
    }
};