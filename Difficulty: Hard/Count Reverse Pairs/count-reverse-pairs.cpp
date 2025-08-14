class Solution {
public:
    int countRevPairs(vector<int>& arr) {
        vector<int> temp = arr;
        return mergeSort(temp, 0, temp.size() - 1);
    }
    
private:
    int mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = 0;
        
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        
        count += countCrossPairs(arr, left, mid, right);
        
        merge(arr, left, mid, right);
        
        return count;
    }
    
    int countCrossPairs(vector<int>& arr, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        return count;
        
    }
    
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> leftArr(mid - left + 1);
        
        vector<int> rightArr(right - mid);
        
        for (int i = 0; i < leftArr.size(); i++) {
            leftArr[i] = arr[left + i];
        }
        for (int i = 0; i < rightArr.size(); i++) {
            rightArr[i] = arr[mid + 1 + i];
        }
        
        int i = 0, j = 0, k = left;
        
        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }
        
        while (i < leftArr.size()) {
            arr[k++] = leftArr[i++];
        }
        while (j < rightArr.size()) {
            arr[k++] = rightArr[j++];
        }
    }
};