class Solution {
public:

bool check(int num){
    int temp = num;
    while(temp){
        int digit = temp%10;
        if(digit == 0) return false;
        temp = temp/10;
    }

    return true;

}
    vector<int> getNoZeroIntegers(int n) {
        

        vector<int> v;
        for(int i = 1 ; i<n ; i++){
            if((n-i)%10 != 0 && check(n-i) && check(i)){

                v.push_back(i);
                v.push_back(n-i);
                break;
            }
        }
        return v;

    }
};