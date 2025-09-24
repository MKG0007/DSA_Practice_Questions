class Solution {
  public:
    bool canServe(vector<int> &bills) {
        // code here

        int size = bills.size();
        if(bills[0]>5) return false;
        int five = 0;
        int ten = 0;
        for(int i = 0 ; i<size ; i++){
            if(bills[i] == 10){
                if(five == 0) return false;
                five--;
                ten++;
            }
            else if(bills[i] == 20){
                if(five == 0) return false;
                else if(ten) five-- , ten--;
                else five -= 3;

                if(five <0) return false;
            }
            else {
                five++;
            }
        }

        return true;
    }
};