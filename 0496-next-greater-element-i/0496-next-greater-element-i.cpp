class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_map<int , int> m;
        stack<int> st;
        vector<int> ans(size1 , 0);


        for(int i = size2-1 ; i>=0 ; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                m[nums2[i]] = -1;
            }
            else{
                m[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }


        for(int i = 0 ; i<size1 ; i++){
            ans[i] = m[nums1[i]];
        }

        return ans;

        
    }
};