class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size-1;

        int rightmax = 0;
        int leftmax = 0;
        int total = 0;
        while(left<right){
            leftmax = max(leftmax , height[left]);
            rightmax = max(rightmax , height[right]);

            if(leftmax<rightmax){
                total += leftmax-height[left];
                left++;
            }
            else{
                total += rightmax - height[right];
                right--;
            }

        }

        return total;
        
    }
};