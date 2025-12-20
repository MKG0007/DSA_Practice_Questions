class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int size = arr.size();
        if(size == 0) return 0;
        if(size == 1){
            if(arr[0] != 1) return 1;
            return arr[0]+1;
        }
        unordered_set<int> m;
        int small = INT_MAX;
        int large = INT_MIN;
        for(int i = 0 ; i<size  ; i++){
            if(arr[i]>= 1e6) continue;
            if(arr[i]>0){
                small = min(small , arr[i]);
                large = max(small , arr[i]);
            }
            m.insert(arr[i]);
        }
        if(small != 1) return 1;
        int num = small+1;
        while(true){
            if(m.find(num) == m.end()) break;
            num++;
        }

        return num;


    }
};