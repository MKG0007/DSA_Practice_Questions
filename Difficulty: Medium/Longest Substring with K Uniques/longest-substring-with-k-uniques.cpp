class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int size = s.length();
        int count = -1;
        unordered_map<char , int> m;
        int j = 0;
        for(int i = 0 ; i<size ; i++){
            m[s[i]]++;
            while(m.size()>k){
                m[s[j]]--;
                if(m[s[j]]  == 0){
                    m.erase(s[j]);
                }
                j++;
            }
            
            if(m.size() == k){
                count = max(count , i-j+1);
            }
        }
        
        return count;
        
    }
};