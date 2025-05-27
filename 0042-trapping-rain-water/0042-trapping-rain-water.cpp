class Solution {
public:
    int trap(vector<int>& h) {
        int size = h.size();
        vector<int> leftMax(size , 0);
        vector<int> rightMax(size , 0);
        leftMax[0] = h[0];
        rightMax[size-1] = h[size-1];

        for(int i = 1 ; i<size ; i++){
            leftMax[i] = max(leftMax[i-1] , h[i]);
        }

        for(int i = size-2 ; i>=0 ; i--){
            rightMax[i] = max(rightMax[i+1] , h[i]);
        }

        int total = 0;

        for(int i = 0 ; i<size ; i++){
            total += min(leftMax[i] , rightMax[i]) - h[i];
        }

        return total;
        
    }
};