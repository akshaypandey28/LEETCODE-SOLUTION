class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<vector<int>>& triangle,int r,int c){
        if(r==triangle.size()-1) return triangle[r][c];
        if(r>=triangle.size() || c>=triangle[r].size()) return 0;

        if(dp[r][c]!=-1) return dp[r][c];

        return dp[r][c]=triangle[r][c] + min(f(triangle,r+1,c),f(triangle,r+1,c+1));  //first is down 
        //second is down and then right
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.clear();
        dp.resize(205,vector<int>(205,-1));
        return f(triangle,0,0);

        //bottom up solution
        // base case
        // for(int i = 0; i < grid[rows-1].size(); i++) {
        //     dp[rows-1][i] = grid[rows-1][i];
        // }
        
        // for(int r = rows - 2; r >= 0; r--) {
        //     for(int c = 0; c < grid[r].size(); c++) {
        //         dp[r][c] = grid[r][c] + min(dp[r+1][c], dp[r+1][c+1]);
        //     }
        // }
        
        
        // return dp[0][0];
    }
};