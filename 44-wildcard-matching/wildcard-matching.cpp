class Solution {
public:
    // Function to check if the remaining part of p contains only '*'
    bool isAllStars(const string &p, int j) {
        for (int k = j; k < p.size(); k++) {
            if (p[k] != '*')
                return false;
        }
        return true;
    }

    // Recursive function to check if p matches s using wildcard pattern matching
    bool wildcardMatchingUtil(const string &s, const string &p, int i, int j, vector<vector<int>> &dp) {
        // Base Cases
        if (i == s.size() && j == p.size())
            return true; // Both strings are fully traversed
        if (i == s.size())
            return isAllStars(p, j); // String is exhausted, check if the rest of the pattern is all '*'
        if (j == p.size())
            return false; // Pattern is exhausted but string is not

        // If the result for this state has already been calculated, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // If the characters at the current positions match or p has a '?'
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = wildcardMatchingUtil(s, p, i + 1, j + 1, dp);
        } else if (p[j] == '*') {
            // '*' matches zero or more characters
            return dp[i][j] = wildcardMatchingUtil(s, p, i + 1, j, dp) || wildcardMatchingUtil(s, p, i, j + 1, dp);
        } else {
            return dp[i][j] = false; // Characters do not match
        }
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        // Create a DP table to memoize results
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return wildcardMatchingUtil(s, p, 0, 0, dp);
    }
};
