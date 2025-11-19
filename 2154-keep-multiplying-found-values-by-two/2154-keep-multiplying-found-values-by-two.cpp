class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> m;
        for(int ele : nums) m.insert(ele);

        while(m.find(original) != m.end()){
            original = original*2;
        }

        return original;
    }
};