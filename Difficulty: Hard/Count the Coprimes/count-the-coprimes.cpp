class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        int n = arr.size(), m = *max_element(arr.begin(), arr.end());
        vector<int> f(m+1);
        for (auto& x : arr) 
            f[x]++;
            
            

        vector<int> mu(m+1), pr, isp(m+1);
        
        
        mu[1] = 1;
        for (int i=2; i<=m; i++) {
            if (!isp[i]) {
                pr.push_back(i);
                mu[i] = -1;
            }
            for (auto& p : pr) {
                long long v = 1LL * i * p;
                if (v > m) break;
                isp[v] = 1;
                if (i % p == 0) {
                    mu[v] = 0;
                    break;
                }
                mu[v] = -mu[i];
                
                
            }
        }

        vector<long long> cnt(m+1);
        for (int d=1; d<=m; d++)
            for (int k=d; k<=m; k+=d)
                cnt[d] += f[k];

        long long ans = 0;
        for (int d=1; d<=m; d++) {
            long long c = cnt[d];
            ans += mu[d] * (c * (c-1) / 2);
        }
        return ans;
    }
};