class Solution {
public:
    long long getDescentPeriods(vector<int>& arr) {
        int size = arr.size();
        if(size == 0) return 0; 

        long long count = 1;
        int j = 0;
        for(int i = 1 ; i<size ;i++){
            if(arr[i]+1 != arr[i-1]){
                j = i;
            }
            count += (i-j+1);
        }

        return count;
        
    }
};