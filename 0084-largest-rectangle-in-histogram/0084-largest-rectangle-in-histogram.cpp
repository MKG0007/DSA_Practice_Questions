class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int size = h.size();
        vector<int> left(size , 0);
        vector<int> right(size , 0);

        stack<int> st;

        for(int i = 0 ; i<size ; i++){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){st.pop();}

        for(int i = size-1 ; i>=0 ; i--){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            if(st.empty()){
                right[i] = size;
            }
            else{
                right[i] = st.top();
            }

            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0 ; i<size ; i++){
            int height = h[i];
            int width = right[i]-left[i]-1;

            maxArea = max(maxArea , height*width);
        }

        return maxArea;
    }
};