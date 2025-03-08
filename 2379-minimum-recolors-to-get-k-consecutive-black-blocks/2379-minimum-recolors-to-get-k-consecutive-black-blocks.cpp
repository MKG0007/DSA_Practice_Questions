class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int crrReColor = 0;
        int ans = 0;

        for(int i = 0 ; i<k ; i++){
            if(blocks[i] == 'W'){
                crrReColor++;

            }

        }

        ans = crrReColor;

        for(int i = k ; i<blocks.size() ; i++){
            int add = blocks[i];
            int sub = blocks[i-k];
            if(add == 'W'){
                crrReColor++;
            }
            if(sub == 'W'){
                crrReColor--;
            }

            ans = min(ans , crrReColor);
        }
        return ans;
    }
};