class Solution {
public:
    bool ans=false;
    bool check(int i,int j,int n,int m){
        if(i<0 or j<0 or i>=n or j>=m) return false;
        return true;
    }
    void dfs(int i,int j,int pI,int pJ,vector<vector<char>>& grid,vector<vector<bool>> &vis,int n,int m,char ch){
        vis[i][j]=1;
        vector<int> dir = {-1, 0, 1, 0, -1}; //direction for up down left right
        for(int k=0; k<4; k++){
            int r=i+dir[k];
            int c=j+dir[k+1];
            if(check(r,c,n,m) and vis[r][c] and grid[r][c]==ch and r!=pI and c!=pJ){
                ans=true;
                return ;
            }
            else if(check(r,c,n,m) and vis[r][c]==0 and grid[r][c]==ch) dfs(r,c,i,j,grid,vis,n,m,ch);
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0) {
                    dfs(i,j,-1,-1,grid,vis,n,m,grid[i][j]);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};