class Solution {
public:
    int minMaxDifference(int num) {
        string snum1 = to_string(num);
        string snum2 = snum1;
        int maxNum = 0;
        int minNum = 0;
        char check = 0;
        for(int i = 0 ; i<snum1.length() ; i++){
            if('0'<= snum1[i] && '9'>snum1[i]){
                check = snum1[i];
                snum1[i] = '9';
                break;     
            }
        }
        for(int i = 0 ; i<snum1.length() ; i++){
            if(check == snum1[i]){
                snum1[i] = '9';
            }
        }

        for(int i = 0 ; i<snum2.length() ; i++){
            if(snum2[i] != '0'){
                check = snum2[i];
                snum2[i] = '0';
                break;
            }
        }

        for(int i = 0 ; i<snum2.length() ; i++){
            if(check == snum2[i]){
                snum2[i] = '0';
            }
        }

        maxNum = stoi(snum1);

        minNum = stoi(snum2);

        return (maxNum - minNum);
    }
};