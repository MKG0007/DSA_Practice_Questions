class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int size = gain.size();

        vector<int> psum(size+1 , 0);
        for(int i = 0 ; i<size ; i++){
            psum[i+1] += psum[i] + gain[i];
        }
        int maxnum = INT_MIN;
        for(int i = 0 ; i<psum.size() ; i++){
            maxnum = max(maxnum , psum[i]);
        }

        return maxnum;
        
    }
};