class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int napp = apple.size();
        int ncap = capacity.size();
        if(ncap == 0) return 0;
        int total = 0;
        sort(capacity.begin() , capacity.end() , greater<int>());
        for(int i = 0 ; i<napp ; i++){
            total += apple[i];
        }

        for(int i =0 ; i<ncap ; i++){
            total -= capacity[i];
            if(total <=0) return i+1;
        }

        return -1;
        
    }
};