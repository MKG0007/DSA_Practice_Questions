class Solution {
public:
    int compress(vector<char>& chars) {
        int size = chars.size();
        if (size == 1) return 1;

        string s = "";
        int i = 0;

        while (i < size) {
            char ch = chars[i];
            int count = 0;

            // count consecutive same characters
            while (i < size && chars[i] == ch) {
                count++;
                i++;
            }

            // add character
            s += ch;

            // add count if > 1
            if (count > 1) {
                s += to_string(count);
            }
        }

        // copy back into chars
        for (int j = 0; j < s.length(); j++) {
            chars[j] = s[j];
        }

        return s.length();
    }
};
