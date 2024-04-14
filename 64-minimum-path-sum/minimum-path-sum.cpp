class Solution {
public:
    vector<vector<int>> dp;
    
    int f(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) return grid[i][j];
        
        // Boundary condition check
        if (i >= m || j >= n) return INT_MAX;
        
        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];
        
        int down = f(grid, i + 1, j, m, n); // downwards
        int right = f(grid, i, j + 1, m, n); // right
        
        return dp[i][j] = grid[i][j] + min(down, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        dp.resize(m, vector<int>(n, -1));
        
        return f(grid, 0, 0, m, n);
    }
};
