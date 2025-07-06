class Solution {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // Your code here
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_map<int , int> m;
        vector<int> ans;

        for(int i = 0 ; i<size2 ; i++){
            m[nums2[i]]++;
        }

        for(int i = 0 ; i<size1 ; i++){
            if(m.find(nums1[i]) != m.end()){
                if(m[nums1[i]] != 0){
                    ans.push_back(nums1[i]);
                }
                m[nums1[i]] = 0;
            }
        }
        return ans;
    }
};