class Solution {
public:
    int findClosest(int x, int y, int z) {
        int speedp1 = abs(z-x);
        int speedp2 = abs(z-y);

        if(speedp1 == speedp2) return 0;
        else if(speedp1<speedp2) return 1;
        else return 2;
    }
};