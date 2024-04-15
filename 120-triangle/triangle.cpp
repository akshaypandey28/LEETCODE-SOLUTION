class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<vector<int>>& triangle,int r,int c){
        if(r==triangle.size()-1) return triangle[r][c];
        if(r>=triangle.size() || c>=triangle[r].size()) return 0;

        if(dp[r][c]!=-1) return dp[r][c];

        return dp[r][c]=triangle[r][c] + min(f(triangle,r+1,c),f(triangle,r+1,c+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.clear();
        dp.resize(205,vector<int>(205,-1));
        return f(triangle,0,0);
    }
};