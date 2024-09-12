class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> curr(m + 1, 0), next(m + 1, 0);
        
        for (int j = 0; j <= m; j++) {
            next[j] = 0;  // Base case: empty string s1
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;  // Move current row to next row for the next iteration
        }
        
        int longest_common_subsequence = next[0];
        return (n - longest_common_subsequence) + (m - longest_common_subsequence);
    }
};
