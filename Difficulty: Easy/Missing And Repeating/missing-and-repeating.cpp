class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int size = arr.size();
        vector<int> count(size+1 , 0);
        
        for(int i = 0 ; i<size ; i++){
            count[arr[i]]++;
        }
        
        int r = -1;
        int m = -1;
        
        for(int i = 1 ; i<=size ; i++){
            if(count[i]>1) r = i;
            
            if(count[i] == 0) m = i;
            
            if(r != -1 && m != -1) break;
        }
        
        return {r , m};
        
    }
};