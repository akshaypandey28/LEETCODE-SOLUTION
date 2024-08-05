class Solution {
public:
    void dfs(vector<vector<char>>& b,int r,int c,int m,int n){
        if(r<0 or r>=m or c<0 or c>=n or b[r][c]!='O') return ;
        b[r][c]='E';

        dfs(b,r-1,c,m,n);
        dfs(b,r+1,c,m,n);
        dfs(b,r,c-1,m,n);
        dfs(b,r,c+1,m,n);
    }
    void solve(vector<vector<char>>& b) {
        int m=b.size();
        int n=b[0].size();
        //mark all border O to E using bfs or dfs
        for(int i=0; i<m; i++){ //for col 0 and col n-1
            dfs(b,i,0,m,n);
            dfs(b,i,n-1,m,n);
        }
        for(int i=0; i<n; i++){ //for row 0 and row m-1
            dfs(b,0,i,m,n);
            dfs(b,m-1,i,m,n);
        }

        //those cells which are E are marked into O and those which are marked with O are marked with X
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(b[i][j]=='E') b[i][j]='O';
                else if(b[i][j]=='O') b[i][j]='X';
            }
        }
        return ;
    }
};