class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {

        // Min-heap to store k largest elements
        priority_queue<int, vector<int>, greater<int>> q;
        
        // Insert first k elements
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }
        
        // Process remaining elements
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] > q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        
        // The top of the min-heap is the k-th largest element
        return q.top();
    }
};
