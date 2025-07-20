class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        unordered_set<int> arrSet(arr.begin(), arr.end());

        int total;
        if (n == 1) total = 9; 
        else total = 9 * pow(10, n - 1);
    
    
        vector<int> allowed;
        for (int d = 1; d <= 9; ++d) { 
            if (arrSet.find(d) == arrSet.end()) {
                allowed.push_back(d);
            }
        }
        if (n > 1 && arrSet.find(0) == arrSet.end()) {
            allowed.push_back(0); 
        }
    
        if (allowed.empty()) return total;
        int valid = 0;
        if (n == 1) {
            valid = allowed.size(); 
        } else {
            int firstDigitChoices = 0;
            for (int d : allowed) {
                if (d != 0) firstDigitChoices++;
            }
            int rest = pow(allowed.size(), n - 1);
            valid = firstDigitChoices * rest;
        }
    
        return total - valid;
    }
};

