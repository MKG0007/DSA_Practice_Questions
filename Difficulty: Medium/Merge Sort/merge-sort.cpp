class Solution {
  public:
  
    void merge(vector<int> &arr , int left , int mid , int right){
        vector<int> ans;
        int l = left;
        int m = mid;
        mid++;
        while(left<=m && mid<=right){
            if(arr[left]<=arr[mid]){
                ans.push_back(arr[left]);
                left++;
            }
            else{
                ans.push_back(arr[mid]);
                mid++;
            }
        }
        
        while(left<=m) ans.push_back(arr[left]), left++;
        while(mid<=right) ans.push_back(arr[mid]), mid++;
        
        for(int i = l ; i<=right ; i++){
            arr[i] = ans[i-l];
        }
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >=r){
            return ;
        }
        int mid = (l+r)/2;
        
        mergeSort(arr , l , mid);
        mergeSort(arr , mid+1 , r);
        merge(arr , l , mid , r);
    }
};