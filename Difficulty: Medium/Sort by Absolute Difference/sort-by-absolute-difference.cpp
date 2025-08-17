class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        vector<pair<int,pair<int,int>>>res;
        for(auto i=0;i<arr.size();i++){
            int it=arr[i];
            res.push_back({abs(x-it),{i,arr[i]}});
        }
        
        
        
        sort(res.begin(),res.end());
        arr.clear();
        for(auto &it:res){
            arr.push_back(it.second.second);
        }
    }
};