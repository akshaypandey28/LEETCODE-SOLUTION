class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());  // Reverse s1 to get s2
        
        vector<int> curr(n + 1, 0), next(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;  // Move current row to next row for the next iteration
        }
        
        return next[0];
    }
};
