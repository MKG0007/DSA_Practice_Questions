class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        
        int n = (int)nums.size();
        if (n <= 1) 
            return 0;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) a[i] = nums[i];
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = (i + 1 < n) ? i + 1 : -1;
        }
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> heap;
        for (int i = 0; i < n - 1; i++) {
            heap.push({a[i] + a[i + 1], i});
        }

        int rest = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) rest++;
        }

        auto bad = [&](int x, int y) -> bool {
            return a[x] > a[y];
        };

        int ans = 0;

        while (rest > 0) {
            auto [v, i] = heap.top(); heap.pop();

            int r = right[i];
            if (r == -1) 
                continue;                 
            if (left[r] != i) 
                continue;            
            if (a[i] + a[r] != v) 
                continue;        

            int li = left[i];
            int rr = right[r];

            if (li != -1 && right[li] == i && bad(li, i)) 
                rest--;
            if (bad(i, r)) 
                rest--;
            if (rr != -1 && left[rr] == r && bad(r, rr)) 
                rest--;

            a[i] = v;

            right[i] = rr;
            if (rr != -1) left[rr] = i;
            left[r] = right[r] = -1;


            if (li != -1 && right[li] == i && bad(li, i)) 
                rest++;
            if (rr != -1 && left[rr] == i && bad(i, rr)) 
                rest++;

            if (li != -1 && right[li] == i) {
                heap.push({a[li] + a[i], li});
            }
            if (rr != -1 && left[rr] == i) {
                heap.push({a[i] + a[rr], i});
            }

            ans++;
        }

        return ans;
    }
};