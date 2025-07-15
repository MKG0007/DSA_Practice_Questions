class Solution {
  public:
    bool divby13(string &s) {
        int remainder = 0;
        for (char digit : s) {
            remainder = (remainder * 10 + (digit - '0')) % 13;
        }
        

        return remainder == 0;
    }
};