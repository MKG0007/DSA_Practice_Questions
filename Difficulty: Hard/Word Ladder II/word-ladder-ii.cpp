// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
    unordered_set<string> adj(wordList.begin() , wordList.end());
        vector<vector<string>> ans; 
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;

        while(!q.empty()){
            vector<string> node = q.front();
            q.pop();

            if(node.size() > level){
                level++;
                for(auto n : usedOnLevel){
                    adj.erase(n);
                }
                usedOnLevel.clear();
            }

             string word = node.back();
             if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(node);
                }
                else if(ans[0].size() == node.size()){
                    ans.push_back(node);

                }
             }
             for(int i = 0; i<word.size() ; i++){
                char original = word[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    word[i] = ch;
                    if(adj.find(word) != adj.end()){
                        node.push_back(word);
                        q.push(node);
                        usedOnLevel.push_back(word);
                        node.pop_back();
                    }
                }
                word[i] = original;
             }
        }
        return ans; 
    }
};