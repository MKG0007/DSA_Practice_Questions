class Solution {
  public:
    int countDigits(int n) {
        // code here
        int count = 0;
        int temp = n;
        while(temp != 0){
            count++;
            temp /= 10;
        }
        return count;
    }
};