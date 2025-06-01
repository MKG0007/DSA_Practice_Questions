// User function Template for C++

class Solution {
  public:
    bool isvalid(vector<int>& stalls , int maxdis , int ncow){
        sort(stalls.begin() , stalls.end());
        int preCowDis = stalls[0];
        int cow = 1;
        
        for(int i = 1 ; i<stalls.size() ; i++){
            if(stalls[i] - preCowDis >= maxdis){
                preCowDis = stalls[i];
                cow++;
            }
        }
        if(cow < ncow) return false;
        return true;
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int size = stalls.size();
        int start = 1;
        int lvalue = INT_MIN;
        int svalue = INT_MAX;
        
        for(int i = 0 ; i<size ; i++){
            lvalue = max(lvalue , stalls[i]);
            svalue = min(svalue , stalls[i]);
        }
        
        int end = lvalue-svalue;
        int mdistance = INT_MIN;
        while(start<=end){
            int mid = start + (end - start)/2;
            
            if(isvalid(stalls , mid , k)){
                mdistance = max(mdistance , mid);
                start = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        
        
        return mdistance;
    }
};