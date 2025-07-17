class Solution {
  public:
    int maxKPower(int n, int k) {
        int x = INT_MAX;
        
        
        vector<int> spf(100000+1,1);
        for(int i = 2;i<=100000;i++){
            
            
            if(spf[i] == 1){
                for(int j = i;j<=100000;j+=i){
                    if(spf[j] == 1){
                        spf[j] = i;
                    }
                }
            }
        }
        unordered_map<int,int> mp,mp1;
        while(k!=1){
            mp[spf[k]]++;
            k/=spf[k];
            
        }
        for(int i = 2;i<=n;i++){
            int num = i;
            while(num!=1){
                mp1[spf[num]]++;
                num /= spf[num];
            }
        }
        for(auto it : mp){
            if(!mp1[it.first]){
                return 0;
            }
            x = min(x,mp1[it.first]/it.second);
        }
        return x;
    }
};