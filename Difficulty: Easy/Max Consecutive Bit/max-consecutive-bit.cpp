class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        int size = arr.size();
        int count1 = 0;
        int count2 = 0;
        int maxi = 0;
        for(int i = 0 ; i<size ; i++){
            if(arr[i] == 0){
                count1++;
                count2 = 0;
            }
            else{
                count1 = 0;
                count2++;
            }
            if(count1<count2){
                maxi = max(count2 , maxi);
            }
            else{
                
                maxi = max(count1 , maxi);
            }
        }
        
        return maxi;
    }
};