class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int size = arr.size();
        int count = 0;
        int left = 0;
        unordered_map<int , int> m;
        for(int right = 0 ; right<size ; right++){
            m[arr[right]]++;
            if(m.size() > 2){
                while(m.size()>2){
                    m[arr[left]]--;
                    if(m[arr[left]] == 0) m.erase(arr[left]);
                    left++;
                }
            }

            if(m.size() <= 2){
                count = max(count , right-left+1);
            }
        }

        return count;
        
    }
};