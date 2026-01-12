class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        if(k == 1) return arr;
        map<int , int> m;
        vector<int> ans;
        for(int i = 0 ; i<k ; i++){
            m[arr[i]]++;
        }
        auto num = *m.rbegin();
        ans.push_back(num.first);
        
        for(int i = k ; i<arr.size() ; i++){
            int add = arr[i];
            int sub = arr[i-k];
            m[sub]--;
            if(m[sub] == 0) m.erase(sub);
            m[add]++;
            auto num = *m.rbegin();
            ans.push_back(num.first);
            
        }
        
        return ans;
    }
};