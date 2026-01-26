const int N=2e6+1;
int freq[N];
class Solution {
    
public:
    static vector<vector<int>> minimumAbsDifference(vector<int>& arr){
        const int n=arr.size();
        int* a=arr.data(); 
        auto [m, M]=minmax_element(a, a+n);
        int bias=*m, range=*M-bias+1;
        memset(freq, 0, sizeof(int)*range); 
        for(int i=0; i<n; i++){
            freq[a[i]-bias]++;
        }
        int  minD=1e9, prevX=-1e9;
        for(int i=0, idx=0; i<range; i++){
            int& f=freq[i];
            while(f--){
                const int x=i+bias;
                a[idx++]=x;
                minD=min(minD, x-prevX);
                prevX=x;
            }
        }

        vector<vector<int>> ans;
        for(int i=1; i<n; i++){
            if (a[i]-a[i-1]==minD)
                ans.push_back({a[i-1], a[i]});
        }
        return ans;
    }
};