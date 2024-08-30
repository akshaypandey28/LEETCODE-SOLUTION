class Solution {
public:
    int solve(vector<int>& coins, int n, int target, vector<vector<int>>& dp,int index) {

        if (target == 0) return 1;

        if (index >= n)  return 0;

        if (target < 0)  return 0;

        // check in dp
        if (dp[index][target] != -1)  return dp[index][target];

        // possibilities
        int include = solve(coins, n, target - coins[index], dp, index);
        int exclude = solve(coins, n, target, dp, index + 1);

        // populate in dp
        return dp[index][target] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        return solve(coins, n, amount, dp, 0);
    }
};