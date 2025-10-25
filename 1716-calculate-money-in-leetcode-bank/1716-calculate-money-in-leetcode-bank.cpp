class Solution {
public:
    int totalMoney(int n) {
        if(n == 1 || n == 0) return n;

        int total = 0;
        int day1 = 0;
        for(int i = 0 ; i<n ; i++){
            day1++;
            int temp = day1;
            int j = 0;
            while(i<n && j<7){
                total += temp;
                temp++;
                j++;
                i++;
            }
            i--;

        }

        return total;
        
    }
};