public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {

        int size = nums.Length;
        IList<IList<int>> ans = new List<IList<int>>();
        Array.Sort(nums);
        for(int i = 0 ; i<size ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = size-1;

            while(j<k){
                int sum = nums[i];
                sum += nums[j];
                sum += nums[k];

                if(sum == 0){
                    ans.Add(new List<int> {nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;

                }
                else if(sum >0) k--;
                else j++;
            }
        }
        

        return ans;
    }
}