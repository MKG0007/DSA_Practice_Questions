
int flatten[400];
char visited[400];
int n;
class Solution {
public:
    void build_flatten(vector<vector<int>>& board) {     
        for (int i=n-1; i>=0; i-=2) {
            for (int j=0; j<n; j++) {
                flatten[(n-1-i)*n+j] = board[i][j]-1;
                if (i-1 >= 0)
                    flatten[(n-i)*n+(n-1-j)] = board[i-1][j]-1;
            }
        }
    }
        
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        build_flatten(board); 
        memset(visited, -1, n*n);
        
        queue<int> q;
        q.push(0);
        visited[0]=0;
        while (!q.empty()) {
            int curr=q.front(); q.pop();
            if (curr==n*n-1){
                return visited[curr];
            } 
            int i0=min(6, n*n-1-curr); 
            for (int i=1; i<= i0; i++) {
                int next=curr+i;           
                if (flatten[next]!=-2) next=flatten[next];
                if (visited[next]!=-1) continue; 
                visited[next]=visited[curr]+1;
                q.push(next);
            }
        }  
        return -1;  
    }
};

