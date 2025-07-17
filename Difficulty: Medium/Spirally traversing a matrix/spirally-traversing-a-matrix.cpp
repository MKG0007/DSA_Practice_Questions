class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &arr) {
        // code here
        int row = arr.size();
        int col = arr[0].size();
        vector<int> ans;
        
        int left = 0;
        int top = 0;
        int right = col-1;
        int btm = row-1;
        while(top <= btm && left <= right){
        for(int i = left ; i<=right ; i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i = top ; i<=btm ; i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top<=btm){
        for(int i = right ; i>=left ; i--){
            ans.push_back(arr[btm][i]);
        }
        }
        
        btm--;
        if(left<=right){
        for(int i = btm ; i>=top ; i--){
            ans.push_back(arr[i][left]);
        }
        }
        left++;
        
    }
    
    return ans;
    }
};