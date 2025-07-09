class Solution {
public:
    int twoEggDrop(int n) {
        int x=1;
        while(x*(x+1)/2<n){
            x++;
        }
        return x;
    }
};