class Solution {
public:
    string minWindow(string s, string t) {
        int size = s.length();
        unordered_map<char, int> m;

        for(char ele : t) m[ele]++;

        int minlen = INT_MAX;
        int count = 0;
        int sindex = -1;
        int j = 0;

        for(int i = 0; i < size; i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]]--;
                if(m[s[i]] >= 0) count++;
            }

            while(count == t.length()){
                if(i - j + 1 < minlen){
                    minlen = i - j + 1;
                    sindex = j;
                }

                if(m.find(s[j]) != m.end()){
                    m[s[j]]++;
                    if(m[s[j]] > 0) count--;
                }

                j++;
            }
        }

        if(sindex == -1) return "";
        return s.substr(sindex, minlen);
    }
};
