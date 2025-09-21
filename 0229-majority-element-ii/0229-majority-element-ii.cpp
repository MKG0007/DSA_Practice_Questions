class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();

        int count1 = 0;
        int count2 = 0;

        int num1 = 0;
        int num2 = 0;

        for(int i = 0 ; i<size ; i++){
            if(count1 == 0 && num2 != nums[i]) num1 = nums[i] , count1 = 1;
            else if (count2 == 0 && num1 != nums[i]) num2 = nums[i] , count2 = 1;
            else if(num1 == nums[i]) count1++;
            else if(num2 == nums[i]) count2++;
            else count1--, count2--;
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0 ; i<size ; i++){
            if(num1 == nums[i]){
                count1++;
            }
            else if(num2 == nums[i]){
                count2++;
            }
        }
        vector<int> ans;
        if(count1> size / 3) ans.push_back(num1);
        if(count2> size / 3) ans.push_back(num2);

        return ans;
    }
};