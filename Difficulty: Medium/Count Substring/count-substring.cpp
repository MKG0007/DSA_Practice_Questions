class Solution {
  public:
    int countSubstring(string arr) {
        int size = arr.length();
        
        int count = 0;
        
        for(int i = 0 ; i<size ; i++){
            vector<int> check(3 , -1);
            for(int j = i ; j<size ; j++){
                check[arr[j]-'a'] = 1;
                if(check[0] + check[1] + check[2] == 3){
                    count += size-j;
                    break;
                }
                
            }
        }
        
        return count;
        
    }
};