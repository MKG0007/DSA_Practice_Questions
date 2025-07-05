class Solution {
public:
    int findLucky(vector<int>& arr) {

        int size = arr.size();
        unordered_map<int , int> freq;


        for(int i = 0 ; i<size ; i++){
            freq[arr[i]]++;
        }
        int ans = -1;
        for(int i = 0 ; i<size ; i++){
            if(freq[arr[i]] == arr[i]){
                ans = max(ans , arr[i]);
            }
        }


        return ans;
        
    }
};