class Solution {
public:
    int subsetXORSum(vector<int>& nums) {

        int result = 0;
        generateSubSets(nums,0,0,result);
        return result;
    }
private:
    void generateSubSets(vector<int>& nums , int index , int currentXOR , int& totalSum) {

        if (index == nums.size()) {
            totalSum += currentXOR;
            return; 
        }


        generateSubSets(nums , index + 1 , currentXOR ^ nums[index] , totalSum);

        generateSubSets(nums , index + 1 , currentXOR , totalSum);
    }
};