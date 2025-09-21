class Solution {
  public:


int merge(vector<int> &arr , int low , int mid , int high){
    vector<int> temp;
    int count = 0;
    int i = low;
    int j = mid+1;
    
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            count += mid-i +1;
            temp.push_back(arr[j]);
            j++;
        }
        
    }
    
    while(i<=mid) temp.push_back(arr[i]), i++;
    while(j<=high) temp.push_back(arr[j]) , j++;
    
    
    for(int i= low ; i<=high ; i++){
        arr[i] = temp[i-low];
    }
    
    return count;
}

int mergeSort(vector<int> &arr , int low , int high){
    int count = 0;
    if(low>= high) return count;
    
    int mid = (low + high)/2;
    
    count += mergeSort(arr , low , mid);
    count += mergeSort(arr , mid+1 , high);
    count += merge(arr , low , mid , high);
    
    return count;
}
    int inversionCount(vector<int> &arr) {
        
        int size = arr.size();
        
        return mergeSort(arr , 0 , size-1);
        
        
        
        
    }
};