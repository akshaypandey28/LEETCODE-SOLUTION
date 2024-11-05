class Solution {
public:
    //same as of surrounding regions
    void dfs(vector<vector<int>>& grid,int r,int c,int m,int n){
        if(r<0 or r>=m or c<0 or c>=n or grid[r][c]!=1) return ;
        grid[r][c]=-1;

        dfs(grid,r-1,c,m,n);
        dfs(grid,r+1,c,m,n);
        dfs(grid,r,c-1,m,n);
        dfs(grid,r,c+1,m,n);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //mark all border 1 to -1 using bfs or dfs
        for(int i=0; i<m; i++){ //for col 0 and col n-1
            dfs(grid,i,0,m,n);
            dfs(grid,i,n-1,m,n);
        }
        for(int i=0; i<n; i++){ //for row 0 and row m-1
            dfs(grid,0,i,m,n);
            dfs(grid,m-1,i,m,n);
        }
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};