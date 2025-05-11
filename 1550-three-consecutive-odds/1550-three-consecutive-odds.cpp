class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int size = arr.size();
        int count = 0;
        for(int i = 0 ; i<size ; i++){
            if(arr[i]%2 != 0){
                count++;
            }
            else{
                count = 0;
            }
            if(count == 3){
                return true;
            }

        }

        return false;
        
    }
};