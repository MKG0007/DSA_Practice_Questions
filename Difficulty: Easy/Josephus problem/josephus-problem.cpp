class Solution {
  public:
    int josephus(int n, int k) {
        
        int p = 0;
        int num = 2;
        while(num<=n){
            p = (k+p)%num;
            num++;
        }
        return p+1;
    }
};