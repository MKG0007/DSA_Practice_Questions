class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        vector<int> count(size+1 , 0);

        for(int i = 0 ; i<size ; i++){
            count[nums[i]]++;
        }

        for(int i = 0 ; i<size ; i++){
            if(count[i]>1) return i;
        }

        return -1;
        
    }
};