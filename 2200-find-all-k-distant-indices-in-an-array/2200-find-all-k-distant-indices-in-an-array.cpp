class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int size1 = nums.size();
        vector<int>ans;

        vector<int> index;
        for(int i = 0 ; i<size1 ; i++){
            if(nums[i] == key){
                index.push_back(i);
            }
        }
        int size2 = index.size();
        if(size2 == 0) return ans;
        if(size2 == size1) return index;

        for(int i = 0 ; i<size1 ;i++){

            for(int j = 0 ; j<size2 ; j++){
                if(abs(i-index[j])<=k){
                    ans.push_back(i);
                    break;
                }
            }

        }

        sort(ans.begin() , ans.end());

        return ans;
    }
};