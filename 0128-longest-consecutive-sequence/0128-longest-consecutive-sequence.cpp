class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> s;

        for(int i = 0 ; i<size ; i++){
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int ele : s){
            if(s.find(ele-1) == s.end()){
                int count = 1;
                int num = ele+1;
                while(s.find(num) != s.end()){
                    num++;
                    count++;
                }
                ans = max(ans , count);
            }

        }
        return ans;
    }
};