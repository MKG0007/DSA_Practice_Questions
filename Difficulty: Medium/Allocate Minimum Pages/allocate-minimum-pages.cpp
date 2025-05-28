class Solution {
  public:
    bool isvalid(vector<int>&arr , int tstudent , int maxpages){
        int s = 1;
        int pages = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            if(arr[i]>maxpages) return false;
            
            if(pages + arr[i]<=maxpages) pages += arr[i];
            else{
                s++;
                pages = arr[i];
            }
        }
        
        if(s>tstudent) return false;
        else return true;
    }
    int findPages(vector<int> &arr, int k) {
        int size = arr.size();
        if(size<k) return -1;
        
        int totalpages = 0;
        for(int num : arr){
            totalpages += num;
        }
        
        int start =0;
        int end = totalpages;
        int ans = -1;
        while(start<=end){
            int mid = start + (end - start)/2;
            
            if(isvalid(arr , k , mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return ans;
        
    }
};