class Solution {
public:
    bool isAllStars(const string &p, int j) {
        // Check if all characters from p[j] to end are '*'
        for (int k = j; k < p.size(); k++) {
            if (p[k] != '*')
                return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        // Create a DP table to memoize results
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: Empty string matches empty pattern
        dp[m][n] = true;
        
        

        // Initialize DP table for patterns that start with '*'
        for (int j = 0; j < n; j++) {
            dp[m][j] = isAllStars(p, j);
        }

        
        // Fill the DP table
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (p[j] == s[i] || p[j] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (p[j] == '*') {
                    // '*' matches zero or more characters
                    dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                }
            }
        }
        
        return dp[0][0];
    }
};
