class Solution {
  public:
    int countSubstring(string s) {
        int size = s.length();
        int count =0;
        vector<int> check(3 , -1);
        for(int i = 0 ; i<size ; i++){
            check[s[i]-'a'] = i;
            if(check[0] != -1 && check[1] != -1 && check[2] != -1){
                count += 1+ min(check[0] , min(check[1] , check[2]));
            }
        }
        
        
        return count;
        
    }
};