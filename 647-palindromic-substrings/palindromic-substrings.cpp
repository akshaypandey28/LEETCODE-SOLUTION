class Solution {
public:
    int dp[1001][1001];
    bool ispalindrome(string& temp, int i, int j) {

        if (i > j) {
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];//0 means false and 1 means true
        }
        if (temp[i] == temp[j]) {
            return dp[i][j]=ispalindrome(temp, i + 1, j - 1);
        }
        return dp[i][j]=false;
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {

                if (ispalindrome(s, i, j)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};