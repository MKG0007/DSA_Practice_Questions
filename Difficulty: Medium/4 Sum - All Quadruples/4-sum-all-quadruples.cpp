class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        int size = arr.size();
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        
        for(int i = 0 ; i<size ; i++){
            if(i>0 && arr[i] == arr[i-1]) continue;
            for(int j = i+1 ; j<size ; j++){
                if(j>i+1 && arr[j] == arr[j-1]) continue;
                int k = j+1;
                int m = size-1;
                
                while(k<m){
                    long long sum = arr[i] + arr[j];
                    sum += arr[k] + arr[m];
                    
                    if(sum == target){
                        ans.push_back({arr[i] , arr[j] , arr[k] , arr[m]});
                        k++;
                        m--;
                        while(k<m && arr[m] == arr[m+1]) m--;
                        while(k<m && arr[k] == arr[k-1]) k++;
                    }
                    else if(sum > target) m--;
                    else k++;
                }
                
                
            }
        }
        
        return ans;
        
    }
};