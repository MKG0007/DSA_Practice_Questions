class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int size = nums.size();
        sort(nums.begin() , nums.end());
        int maxi = 0;
        int crrele = INT_MIN;
        int count = 0;
        for(int i = 0 ; i<size ; i++){
            if(nums[i]-1 == crrele){
                count++;
                crrele = nums[i];
            }
            else if(nums[i] != crrele){
                count = 1;
                crrele = nums[i];
            }

            maxi = max(maxi , count);
        }
        
      return maxi; 
    }
};