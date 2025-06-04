class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = strs[0];

        for(int i = 1 ; i<strs.size() ; i++){
            int j = 0;
            int index = 0;
            while(j<ans.length() && j<strs[i].length()){
                if(ans[j] == strs[i][j]){
                    index++;
                }
                else{
                    break;
                }
                j++;
            }
            ans = strs[i].substr(0 , index);
        }
        return ans;
    }
};