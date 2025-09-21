class Solution {
  public:

    void merge(vector<int> &nums , int low , int mid , int high){
        int i = low ;
        int j = mid+1;
        vector<int> temp;

        while(i<=mid && j<=high){
            if(nums[i]<= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(j<=high) temp.push_back(nums[j]) , j++;

        while(i<=mid) temp.push_back(nums[i]) , i++;

        for(int i = low ; i<=high ; i++){
            nums[i] = temp[i-low];
        }


    }

    int countPairs(vector<int> &nums , int low , int mid , int high){
        int count = 0;
        int right = mid+1;
        for(int i = low ; i<=mid ; i++){
            while(right<=high && nums[i]> (long long)2*nums[right]) right++;
            count += right-(mid+1);
        }

        return count;
    }


    int mergeSortCount(vector<int> &nums , int low , int high){
        int count = 0;
        if(low>=high) return count;

        int mid = (low+high)/2;

        count += mergeSortCount(nums , low , mid);
        count += mergeSortCount(nums , mid+1 , high);
        count += countPairs(nums , low , mid , high);
        merge(nums , low , mid , high);
        return count;
    }
    int countRevPairs(vector<int> &arr) {
        int size = arr.size();
        
        return mergeSortCount(arr , 0 , size-1);
        
    }
};