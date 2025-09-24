class Solution {
  public:
    int maxChildren(vector<int> &g, vector<int> &s) {
        // code here
        int size1 = g.size();
        int size2 = s.size();
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int count = 0;
        int i = 0;
        int j = 0;

        while(i<size1 && j<size2){
            if(g[i] <= s[j]){
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};