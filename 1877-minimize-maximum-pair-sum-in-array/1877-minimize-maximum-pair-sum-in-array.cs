public class Solution {
    public int MinPairSum(int[] nums) {
        Array.Sort(nums);

        int left = 0;
        int right = nums.Length-1;
        int ans = int.MinValue;
        while(left<right){
            ans = Math.Max(ans , (nums[left]+nums[right]));
            left++;
            right--;
        }
        return ans;
    }
}