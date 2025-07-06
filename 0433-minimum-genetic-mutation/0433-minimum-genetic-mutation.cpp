class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> adj(bank.begin() , bank.end());
        queue<pair<string , int>> q;
        q.push({startGene , 0});

        while(!q.empty()){
            string node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(node == endGene) return level;

            for(int i = 0 ; i<node.length() ; i++){
                char original = node[i];
                for(char ch = 'A' ; ch<='Z' ; ch++){
                    node[i] = ch;
                    if(adj.find(node) != adj.end()){
                        q.push({node , level+1});
                        adj.erase(node);
                    }
                }
                node[i] = original;
            }
        }

        return -1;
        
    }
};