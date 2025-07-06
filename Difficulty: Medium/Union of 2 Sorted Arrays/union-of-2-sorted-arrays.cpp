class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        int size1 = a.size();
        int size2 = b.size();
        int s1 = 0;
        int s2 = 0;
        vector<int> ans;
        while(s1<size1 && s2<size2){
            if(a[s1]<=b[s2]){
                if(ans.size() == 0 || ans.back() != a[s1]){
                    ans.push_back(a[s1]);
                }
                s1++;
            }
            else{
                if(ans.size() == 0 || ans.back() != b[s2]){
                    ans.push_back(b[s2]);
                } 
                s2++;
            }
        }
        
        while(s1<size1){
            if(ans.back() != a[s1]){
                ans.push_back(a[s1]);
            }
            s1++;
        }

        while(s2<size2){
            if(ans.back() != b[s2]){
                ans.push_back(b[s2]);
            }
            s2++;
        }
        
        return ans;
        // return vector with correct order of elements
    }
};