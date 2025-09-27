public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int size = nums.Length;

        int[] ans = {-1 , -1};
        for(int i = 0 ; i<size ; i++){
            for(int j = i+1 ; j<size ; j++){
                int sum = nums[i]+nums[j];
                if(sum == target){
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                    
                } 
            }

        }

        return ans;
    }
}