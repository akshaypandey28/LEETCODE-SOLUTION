class Solution {
public:
    vector<int> dp;
    int fbu(string &str) {
        dp.clear();
        dp.resize(5005, 0);
        dp[0] = (str[0] != '0');
        if(str.size() > 1) {
            if(str[1] != '0') dp[1] += dp[0];
            if(str[1-1] - '0' > 0 and (str[0] - '0')*10 + (str[1] - '0') <= 26) dp[1]++;
        }
        for(int i = 2; i < str.size(); i++) {
            int ans = 0;
            if(str[i] - '0' > 0) {
                ans+=dp[i-1];
            } 
            if(str[i-1]-'0' > 0 and (str[i-1] - '0')*10 + (str[i] - '0') <= 26) {
                ans += dp[i-2];
            }
            dp[i] = ans;
        }
        return dp[str.size() - 1];

}
    int numDecodings(string s) {
        return fbu(s);
    }
};