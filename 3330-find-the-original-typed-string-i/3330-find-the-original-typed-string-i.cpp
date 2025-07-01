class Solution {
public:
    int possibleStringCount(string word) {

        int size = word.length();
        int check = 0;
        int ans = 1;
        for (int i = 1; i < size; i++) {
            if (word[i - 1] != word[i]) {
                ans += check;
                check = 0;
            }
            if (word[i - 1] == word[i]) {
                check++;
            }
        }
        if (check != 0) {
            ans += check;
        }

        return ans;
    }
};