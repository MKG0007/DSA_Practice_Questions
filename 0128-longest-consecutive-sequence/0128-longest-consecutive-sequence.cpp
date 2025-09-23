class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        unordered_set<int> m;
        for(int ele : nums) m.insert(ele);

        int maxi = 1;

        for(int nums : m){
            if(m.find(nums -1) == m.end()){
                int num = nums+1;
                int count = 1;
                while(m.find(num) != m.end()){
                    count++;
                    num += 1;
                }

                maxi = max(maxi , count);
            }
        }

        return maxi;
        
    }
};