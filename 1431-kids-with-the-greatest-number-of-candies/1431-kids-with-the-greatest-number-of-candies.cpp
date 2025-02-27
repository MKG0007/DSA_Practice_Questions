class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        for(int i = 0 ; i<candies.size() ; i++){
            int crr = candies[i] + extraCandies;
            int check = 0;
            for(int j = 0 ; j<candies.size() ; j++){
                if(j != i && crr<candies[j]){
                    check = 1;
                }
            }
            if(check){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
    }
};