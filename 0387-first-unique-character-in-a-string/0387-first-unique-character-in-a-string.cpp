class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.length();
        unordered_map<int , int> m;
        queue<int> q;

        for(int i = 0 ; i<size ; i++){
            if(m.find(s[i]) == m.end()){
                q.push(i);
            }
            m[s[i]]++;

            while(!q.empty() && m[s[q.front()]]>1){
                q.pop();
            }
        }

        if(q.empty()) return -1;

        return q.front();
        
    }
};