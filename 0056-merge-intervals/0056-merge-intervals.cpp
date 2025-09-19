class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int size = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin() , arr.end());

        for(int i =0 ; i<size ; i++){
            int start = arr[i][0];
            int end = arr[i][1];

            if(!ans.empty() && end <= ans.back()[1]) continue;

            for(int j = i+1 ; j<size ; j++){
                if(arr[j][0]<=end){

                    end = max(end , arr[j][1]); 
                }
                else{
                    i = j-1;
                    break;
                }
            }


            ans.push_back({start , end});
        }

        return ans;
    }
};