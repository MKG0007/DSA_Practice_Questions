
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int size = arr.size();
        int check = (size/3)+1;
        unordered_map<int , int> m;
        vector<int> ans;
        
        for(int i = 0 ; i<size ; i++){
            m[arr[i]]++;
            if(m[arr[i]] == check){
                ans.push_back(arr[i]);
            }
            
        }
        
        sort(ans.begin() , ans.end());
        
        return ans;
    }
};