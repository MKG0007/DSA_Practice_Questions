class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int size = nums.size();
        int count = 0;

        for(int i =0 ; i<size ; i++){
            if(nums[i]%3 != 0){
                int n1 = nums[i];
                int n2 = nums[i];
                int c1 =0;
                int c2 =0;
                while(n1%3 && n2%3){
                    if(n1%3 != 0) n1 = n1+1 , c1++;
                    if(n2%3 != 0) n2 = n2-1 , c2++;
                }

                if(n1%3 == 0){
                    nums[i] = n1;
                    count += c1;
                }
                else{
                    nums[i] = n2;
                    count += c2;
                }
            }
        }
        return count;
        
    }
};