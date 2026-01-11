class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int size = s1.length();
        int len = s2.length();
        string ans = "";
        int mlen = INT_MAX;
        for(int i = 0 ; i<size ; i++){
            string temp = "";
            int k = 0;
            for(int j = i ; j<size ; j++){
                if(k<len){
                    if(s1[j] == s2[k]) k++;
                    
                }else break;
                
                if(k>0) temp+= s1[j];
                
            }
            if(k>=len && temp.length()<mlen){
                ans = temp;
                mlen = temp.length();
            }
        }
        return ans;
        
        
    }
};
