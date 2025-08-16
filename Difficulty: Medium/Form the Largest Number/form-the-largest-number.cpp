class Solution {
  public:
    static bool myfunction(string &a,string &b)
    {
         string  t1 = a+b;
         string t2 = b+a;
         if(t1>t2)
         return true;
         else
          return false;
    }
    
    
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> st;
        for(auto it:arr)
        {
            st.push_back(to_string(it));
        }
        
        
        sort(st.begin(),st.end(),myfunction);
        
        string ans = "";
        for(auto it:st)
        {
            ans+=it;
        }
        
        int i=0;
        while(i<ans.size()-1 && ans[i]=='0')
        {
            i++;
        }
        
        ans = ans.substr(i);
        return ans;
    }
};