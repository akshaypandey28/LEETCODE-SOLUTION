class Solution {
public:
    int n, m;
    vector<vector<int>> grid, dp;
    int f(int i, int j) {
        if(i == n-1 and j == m-1) return 1;
        if(i < 0 or j < 0 or i >= n or j >= m) return 0;
        if(grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i, j+1) + f(i+1, j);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        n = grid.size();
        m = grid[0].size();
        dp.clear();
        dp.resize(105, vector<int> (105, -1));
        if(obstacleGrid[n-1][m-1]==1) return 0;
        return f(0,0);
    }
};