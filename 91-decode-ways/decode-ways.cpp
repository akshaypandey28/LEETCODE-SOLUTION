#define ll long long int
class Solution {
public:
    vector<ll> dp;
    int f(string &str, int i) {
    if(i <= 0) return 1;
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    if(str[i] - '0' > 0) {
        ans+=f(str, i-1);
    } 
    if(str[i-1]-'0' > 0 and (str[i-1] - '0')*10 + (str[i] - '0') <= 26) {
        ans += f(str, i-2);
    }

    return dp[i] = ans;
}
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        dp.clear();
        dp.resize(105, -1);
        return f(s,s.size()-1);
    }
};