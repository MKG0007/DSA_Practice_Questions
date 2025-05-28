class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    int size = arr.size();
    int start = 1;
    int end = size-2;
    if(size == 3) return 1;
    while(start<=end){
        int mid = start + (end -start)/2;
        if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
            return mid;
        }
        else if(arr[mid-1]<arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
        return -1;
    }
};