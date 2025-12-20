class Solution {
public:
    int minDeletionSize(vector<string>& arr) {
        int rows = arr.size(); 
        int cols = arr[0].length();

        int count = 0;
        for(int i = 0 ; i<cols ; i++){
            for(int j = 1 ; j<rows ; j++){
                if(arr[j-1][i] > arr[j][i]){
                    count += 1;
                    break;
                }
            }
        }
        return count;
        
    }
};