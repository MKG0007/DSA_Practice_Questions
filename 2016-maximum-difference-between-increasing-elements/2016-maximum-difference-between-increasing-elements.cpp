class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int size = nums.size();
        int maxDiff = -1;
        stack<int> st;
        // sort(nums.begin() , nums.end());

        int numi = INT_MAX;
        for(int i = 0 ; i<size ; i++){
            int numj = nums[i];
            while(!st.empty() && nums[i]>nums[st.top()]){
                numi = min(numi , nums[st.top()]); 
                st.pop();
            }
            if(numi<numj){
                maxDiff = max(maxDiff , (numj-numi));

            }
            st.push(i);
        }

        return maxDiff;
        
    }
};