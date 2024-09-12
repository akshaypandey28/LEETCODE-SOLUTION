class Solution {
public:
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        dp.clear();
        dp.resize(n+1, vector<int>(n+1, 0));
        
        string s2 = s1;  // Copy s1 to s2
        reverse(s2.begin(), s2.end());  // Reverse s2
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(s1[i] == s2[j]) dp[i][j] = 1+ dp[i + 1][j+1];
                else dp[i][j]= max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
