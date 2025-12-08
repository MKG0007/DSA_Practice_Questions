class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int size = arr.size();
        
        int count = 0;
        int j = 0;
        unordered_map<int , int> m;
        for(int i = 0 ; i<size ; i++){
            m[arr[i]]++;
            
            while(m.size()>2){
                m[arr[j]]--;
                if(m[arr[j]] == 0) m.erase(arr[j]);
                
                j++;
            }
            
            if(m.size()<=2){
                count = max(count , i-j+1);
            }
        }
        
        
        return count;
        
    }
};