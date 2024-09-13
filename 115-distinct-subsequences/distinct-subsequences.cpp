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
            swap(curr, next);
        }

        return next[0];  // The result is stored at next[0]
    }
};
