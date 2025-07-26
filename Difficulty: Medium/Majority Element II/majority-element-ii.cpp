class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int size = arr.size();
        unordered_map<int , int> m;
        vector<int> ans;
        
        for(int i = 0 ; i<size ; i++){
            m[arr[i]]++;
            
        }
        
        for(auto ele : m){
            if(ele.second>size/3){
                ans.push_back(ele.first);
            }
        }
        sort(ans.begin() , ans.end());
        
        return ans;
    }
};