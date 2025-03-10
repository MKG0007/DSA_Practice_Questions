class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = 0;
        int index2 = 0;
        vector<int> temp;

        while(index1<m && index2<n){
            if(nums1[index1]<=nums2[index2]){
                temp.push_back(nums1[index1]);
                index1++;
            }
            else{
                temp.push_back(nums2[index2]);
                index2++;
            }
        }

        while(index2<n) temp.push_back(nums2[index2++]);
        while(index1<m) temp.push_back(nums1[index1++]);

        for(int i = 0 ; i<temp.size() ; i++){
            nums1[i] = temp[i];
        }

        
        
    }
};