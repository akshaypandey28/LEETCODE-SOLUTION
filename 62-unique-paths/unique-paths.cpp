class Solution {
public:
    vector<vector<int>> dp;
    int f(int m,int n,int i,int j){
        if(i==m-1 and j==n-1){
            return 1;
        }
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=f(m,n,i+1,j) + f(m,n,i,j+1);
    }
    int uniquePaths(int m, int n) {
        dp.clear();
        dp.resize(m, vector<int>(n, -1));
        int ans=0;
        return f(m,n,0,0);
       // return ans;
    }
};