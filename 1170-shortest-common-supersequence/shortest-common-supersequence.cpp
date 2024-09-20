class Solution {
public:
    vector<vector<int>> dp;
    string shortestCommonSupersequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.clear();
        dp.resize(1005, vector<int>(1005, 0));
        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];

                else
                    dp[i][j] = max(dp[i + 1][j],
                                   dp[i][j + 1]); // lcs(select , not select) ,
                                                  // lcs(not select , select)
            }
        }
        int i = 0;
        int j = 0;
        string ans = "";
        while (i < n and j < m) {
            if (text1[i] == text2[j]) {
                ans += text1[i];
                i++;
                j++;
            } else if (dp[i + 1][j] > dp[i][j +1]) {
                ans += text1[i];
                i++;
            } else {
                ans += text2[j];
                j++;
            }
        }
        while(i<n){
            ans += text1[i];
            i++;
        }
        while(j<m){
            ans += text2[j];
            j++;
        }
        return ans;
    }
};