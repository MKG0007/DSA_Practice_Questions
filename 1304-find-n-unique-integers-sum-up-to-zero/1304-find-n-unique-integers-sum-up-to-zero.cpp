class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};
        if(n == 2) return {-1 , 1};
        vector<int> ans;
        int temp = n/2;
        if(n%2 != 0) ans.push_back(0); 
        
        for(int i = 1 ; i<=temp ; i++){
            ans.push_back(i);
            ans.push_back(-i);
        }


        return ans;





        
    }
};