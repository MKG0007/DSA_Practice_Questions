class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size() == 1) return cardPoints[0];
        int crrScore = 0;
        for(int i = 0 ; i<k ; i++){
            crrScore += cardPoints[i];
        }


        int ans = crrScore;

        for(int i = k-1 ; i>=0 ; i--){
            crrScore -= cardPoints[i];
            crrScore += cardPoints[cardPoints.size()-k+i];
            ans = max(ans , crrScore);
        }
        return ans;
        
    }
};