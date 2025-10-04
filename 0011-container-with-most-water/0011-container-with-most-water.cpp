class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int start = 0;
        int end = size - 1;
        int mvolume = 0;
        while(start < end){
            int width = end - start;
            int breath = min(height[start] , height[end]);
            int cvolume = width*breath;
            mvolume = max(mvolume , cvolume);
            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return mvolume;
        
    }
};