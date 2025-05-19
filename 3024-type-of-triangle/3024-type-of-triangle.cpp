class Solution {
public:
    string triangleType(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int , int> m;
        int eSides = 0;
        for(int i = 0 ; i<size ; i++){
            m[nums[i]]++;
            eSides = max(eSides , m[nums[i]]);
        }

        if(eSides == 3){
            return "equilateral";
        }
        else if(eSides == 2){
            return "isosceles";
        }
        else{
            return "scalene";
        }
    }
};