class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        unordered_set<string> checker(wordList.begin() , wordList.end());
        
        queue<pair<string , int>> q;
        q.push({startWord , 1});
        
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == targetWord) return level;
            
            for(int i = 0 ; i<word.length() ; i++){
                char original = word[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    word[i] = ch;
                    if(checker.find(word) != checker.end()){
                        q.push({word , level+1});
                        checker.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};