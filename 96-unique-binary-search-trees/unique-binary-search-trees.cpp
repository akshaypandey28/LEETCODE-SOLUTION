class Solution {
public:
    vector<int> dp;
    int numTrees(int n) {
        dp.clear();
        dp.resize(30, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        //f(n) nikalna hai to f(n-1) f(n-2) etc sare answer hone chahiye
        for(int i = 3; i <= n; i++) { // order
            // f(i)
            for(int k = 1; k <= i; k++) {
            // k -> potential root
                dp[i] += dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }
};