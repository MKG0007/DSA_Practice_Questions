class Solution {
public:
    int countall(vector<int> &arr, int t) {
        int n = arr.size();
        unordered_map<int, int> freq;
        int j = 0, total = 0;

        for(int i = 0; i < n; i++) {
            freq[arr[i]]++;

            while(freq.size() > t) {
                freq[arr[j]]--;
                if(freq[arr[j]] == 0)
                    freq.erase(arr[j]);
                j++;
            }

            total += (i - j + 1);
        }

        return total;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return countall(arr , k)-countall(arr , k-1);
    }
};