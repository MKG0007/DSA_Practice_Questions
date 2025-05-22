class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int size = h.size();
        vector<int> right(size , 0);
        vector<int> left(size , 0);
        stack<int> rs;

        for(int i = size-1 ; i>=0 ; i--){
            while(!rs.empty() && h[rs.top()]>=h[i]){
                rs.pop();
            }
            if(rs.empty()){
                right[i] = size;
            }
            else{
                right[i] = rs.top();
            }
            rs.push(i);
        }

        while(!rs.empty()){
            rs.pop();
        }

        for(int i = 0 ; i<size ; i++){
            while(!rs.empty() && h[rs.top()]>=h[i]){
                rs.pop();
            }
            if(rs.empty()){
                left[i] = -1;
            }
            else{
                left[i] = rs.top();
            }
            rs.push(i);
        }
        int maxArea = 0;
        for(int i = 0 ; i < size ; i++){
            int width = right[i]-left[i] -1;
            int height = h[i];
            maxArea = max(maxArea , width*height);
        }
        return maxArea;

    }
};