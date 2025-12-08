class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
        int size = s.length();
        
        int count = 0;
        int j = 0;
        int maxf = 0;
        unordered_map<char , int> m;
        for(int i = 0  ; i<size ; i++){
            m[s[i]]++;
            maxf = max(maxf , m[s[i]]);
            if((i-j+1)-maxf > k){
                m[s[j]]--;
                
                j++;
            }
            if((i-j+1)-maxf <=k){
                count = max(count , i-j+1);
            }
            
        }
        
        return count;
    }
};