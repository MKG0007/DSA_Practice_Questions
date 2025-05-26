class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> v1(size1 , 0);
        unordered_map<int , int> m;

        stack<int> st;

        for(int i = size2-1 ; i>=0 ; i--){
            while(!st.empty() && nums2[i]>=st.top()){
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
            v1[i] = m[nums1[i]];
        }

        return v1;
    }
};