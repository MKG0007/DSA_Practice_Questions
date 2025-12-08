class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        
        int maxsc = INT_MIN;
        int crrsc = 0;
        for(int i = 0 ; i<k ; i++){
            crrsc += cardPoints[i];
        }
        
        maxsc = crrsc;
        int j = size-1;
        for(int i = k-1 ; i>=0 ; i--){
            crrsc -= cardPoints[i];
            crrsc += cardPoints[j];
            maxsc = max(maxsc , crrsc);
            j--;
        }
        
        return maxsc;
    }
};
