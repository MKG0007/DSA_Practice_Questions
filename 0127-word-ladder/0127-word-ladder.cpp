class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // using set the to make the checking easy and less time consuming
        set<string> checkList;
        for(auto ele : wordList){
            checkList.insert(ele);
        }
        
        // using queue for bfs(storing changed word and level)
        queue<pair<string , int>> q;
        q.push({beginWord , 1});

        while(!q.empty()){

            string node = q.front().first;
            int level = q.front().second;

            if(node == endWord) return level;
            q.pop();

            for(int i = 0 ; i<node.length() ; i++){
                char original = node[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    node[i] = ch;
                    if(checkList.find(node) != checkList.end()){
                        q.push({node , level+1});
                        checkList.erase(node);
                    }
                }
                node[i] = original;

            }
        }

        return 0;
        
    }
};