const int prime = 1e9 + 7;

class Solution {
public:
    int numDistinct(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<int> curr(m + 1, 0), next(m + 1, 0);
        next[m] = 1;  // Base case: When s2 is empty, there's exactly 1 subsequence that matches
        // Loop through the strings from end to start
        for (int i = n - 1; i >= 0; i--) {
            curr[m] = 1;  // For an empty s2, there's always 1 subsequence that matches
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    // If characters match, include both options and apply modulo to avoid overflow
                    curr[j] = (next[j + 1] + next[j]) % prime;
                } else {
                    // If characters don't match, skip the current character in s1
                    curr[j] = next[j] % prime;
                }
            }
            // Move current row to next for the next iteration
            next=curr;
        }

        return curr[0];  // The result is stored at next[0]
    }
};



/* 
const int prime = 1e9 + 7;

class Solution {
public:
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // Base case: If we have matched all of s2
        if (j == s2.size()) return 1;

        // Base case: If we have exhausted s1 but not s2
        if (i == s1.size()) return 0;

        // Check if the result is already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive cases
        if (s1[i] == s2[j]) {
            // Include the match and skip the match
            dp[i][j] = (helper(i + 1, j + 1, s1, s2, dp) + helper(i + 1, j, s1, s2, dp)) % prime;
        } else {
            // Skip the current character in s1
            dp[i][j] = helper(i + 1, j, s1, s2, dp) % prime;
        }

        return dp[i][j];
    }

    int numDistinct(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // Initialize a DP table with -1 for memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(0, 0, s1, s2, dp);
    }
};

 */
