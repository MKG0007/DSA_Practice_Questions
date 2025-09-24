// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int size = bt.size();
        sort(bt.begin() , bt.end());
        int tim = 0;
        int wait = 0;
        for(int i = 0 ; i<size ; i++){
            tim += wait;
            wait += bt[i];
        }
        tim = tim/size;
        
        return tim;
    }
};