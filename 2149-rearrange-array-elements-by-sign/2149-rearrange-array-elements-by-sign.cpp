class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int size = nums.size();
        if(size <=1) return nums;
        vector<int> negative;
        vector<int> positive;

        for(int i = 0 ; i<size ; i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);
            }
            else{
                negative.push_back(nums[i]);
            }
        }

        int check = 1;
        int indexp = 0;
        int indexn = 0;
        for(int i = 0 ; i<size ; i++){
            if(check){
                nums[i] = positive[indexp];
                indexp++;
                check = 0;
            }
            else{
                nums[i] = negative[indexn];
                indexn++;
                check = 1;
            }
        }

        return nums;
    }
};