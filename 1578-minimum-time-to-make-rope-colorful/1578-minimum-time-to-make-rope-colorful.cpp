class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int ans=0;

        int pre=0;

        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[pre]){

                
                if(arr[pre]>=arr[i]){
                    ans+=arr[i];
                    continue;
                }else{
                    ans+=arr[pre];
                    pre=i;
                }
            }else{
                pre=i;
            }
        }
        return ans;
    }
};