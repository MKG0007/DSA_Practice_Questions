class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int t = n/2;
        if(n%2==1)t++;
        
        
        int ans=0,f=0;
        map<int,int> m;
        
        
        for(int i=0;i<n;i++){
            if(arr[i]%k==0)ans++;
            
            else m[k-arr[i]%k]++;
            
            if(ans>=t)return f;            
            
        }
        for(auto i:m){
            while(i.second>0){
                ans++;
                f+=i.first;
                i.second--;
                if(ans>=t)return f;            
            }   
        }
        return f;
    }
};