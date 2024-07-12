class Solution {
public:
//i and x for bottom movement
//j and y for right movement
    int dp[55][55][55];
    int f(int i,int j,int x,int y,vector<vector<int>>& grid){
        int n=grid.size();
        if(i>=n || j>=n || x>=n || y>=n or grid[i][j]==-1 or grid[x][y]==-1) return INT_MIN; //(i,j) for tourist 1 and (x,y) for tourist 2
        //agr dono ek sath hi interesting location pr pahuch rhe hai to bhi location ek bar hi count hoga
        //aur alg alg pahuch rhe hai to bhi ek bar hi count hoga aur ye must hai reach krenge location pr
        //overall grid[n-1][n-1] ye ek bar hi count hona hai

        if(i==n-1 and j==n-1) return grid[i][j]==1;

        if(dp[i][j][x]!=-1) return dp[i][j][x];

        int result=INT_MIN;
        //ek point choose krke aage ke points se jo maximum answer hoga usme current interseting location add kr denge 

        result = max(result, f(i+1, j, x+1, y,grid)); 
        result = max(result, f(i+1, j, x, y+1,grid));
        result = max(result, f(i, j+1, x+1, y,grid));
        result = max(result, f(i, j+1, x, y+1,grid));

        // If result is still INT_MIN, it means all moves lead to invalid states
        if (result == INT_MIN) return dp[i][j][x] = INT_MIN;


        result += (grid[i][j] == 1);
        result += (grid[x][y] == 1);

        // remove repition agr dono tourist same interseting location pr hai isliye -- ho rha hai double count nhi hona chahiye same location
        if(i == x and j == y and grid[i][j] == 1) result--;

        return dp[i][j][x] = result;


    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        int result = f(0, 0, 0, 0, grid);

        // If the result is INT_MIN, it means no valid path was found
        return result == INT_MIN ? 0 : result;
    }
};