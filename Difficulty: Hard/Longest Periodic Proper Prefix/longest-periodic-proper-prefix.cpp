class Solution {
  public:
    int getLongestPrefix(string &s) {
        int n = s.size();
        if (n <= 1) return -1;

        vector<int> z(n, 0);
        
        
        z[0] = n;
        for (int i=1, l=0, r=0; i<n; ++i) {
            if (i <= r) z[i] = min(r-i+1, z[i-l]);
            
            
            
            while (i+z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) { 
                l = i; 
                r = i + z[i] - 1; 
            }
        }

        for (int i = n - 1; i >= 1; --i) {
            if (z[i] >= n - i) return i;
        }
        return -1;
    }
};