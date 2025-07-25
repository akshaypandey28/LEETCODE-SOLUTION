class Solution {
public:
    int dir[5]={-1,0,1,0,-1};
    int solve(vector<vector<int>>& matrix,int r,int c,vector<vector<int>>& dp){
        int m=matrix.size();
        int n=matrix[0].size();
        if(dp[r][c]!=-1) return dp[r][c];
        int length=1; //at least the cell itself is always a longestIncreasingPath
        for(int i=0; i<4; i++){
            int nr=r+dir[i];
            int nc=c+dir[i+1];
            if(nr>=0 and nr<m and nc>=0 and nc<n and matrix[nr][nc] > matrix[r][c]){
                length=max(length,1+solve(matrix,nr,nc,dp));
            }
        }
        return dp[r][c]=length;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans=max(ans,solve(matrix,i,j,dp));
            }
        }
        return ans;  
    }
};