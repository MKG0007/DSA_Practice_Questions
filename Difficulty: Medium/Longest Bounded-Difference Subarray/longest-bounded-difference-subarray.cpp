class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int> mini;
        deque<int> maxi;
        int maxL = 0, len = 0;
        int l = 0, r = 0;
        int ans = -1;
        while(r < n) {
            while(!mini.empty() && arr[mini.back()] > arr[r]) {
                mini.pop_back();
            }
            mini.push_back(r);
            while(!maxi.empty() && arr[maxi.back()] < arr[r]) {
                maxi.pop_back();
            }
            maxi.push_back(r);
            while(!mini.empty() && !maxi.empty() && 
            arr[maxi.front()] - arr[mini.front()] > x) {
                if(mini.front() > maxi.front()) {
                    l = maxi.front() + 1;
                    maxi.pop_front();
                }
                else{
                    l = mini.front() + 1;
                    mini.pop_front();
                }
            }
            len = r - l + 1;
            
            if(len > maxL) {
                ans = r;
                maxL = len;
            }
            r++;
        }
        vector<int> res;
        
        for(int i = ans - maxL + 1; i <= ans; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};