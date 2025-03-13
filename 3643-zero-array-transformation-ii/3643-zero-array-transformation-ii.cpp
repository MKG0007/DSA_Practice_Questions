class Solution {
public:
    static int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n=nums.size(), m=queries.size();
        vector<int> freq(n+1);
        int op=0, k=0;
        for(int i=0; i<n; i++){
            for( ; op < nums[i]-freq[i]; k++){
                if (k>=m) return -1;
                const int l=queries[k][0], r=queries[k][1], v=queries[k][2];
                if (r<i) continue;
                freq[max(l, i)]+=v;
                freq[r+1]-=v;
            }
            op+=freq[i];
        }
        return k;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();  