class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        int left = 0, right = 0, count = 0;
        unordered_map<char, int> m;

        while(right < size){
            if(m.find(s[right]) != m.end()){
                left = max(left, m[s[right]] + 1);
            }
            m[s[right]] = right;
            count = max(count, right - left + 1);
            right++;
        }
        return count;
    }
};
