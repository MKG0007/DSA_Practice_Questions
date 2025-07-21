// User function Template for C++

class Solution {
  public:
    void sum(int &a , int &b){
        a += 1;
        b += 2;
    }
    vector<int> passedBy(int a, int &b) {
        sum(a , b);
        
        return {a , b};
        
    }
};