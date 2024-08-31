#define ll long long int
class Solution {
public:
    vector<ll> dp;
    int f(string &s,int i){
        if(i>=s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        if(s[i]-'0'!=0) ans+=f(s,i+1);
        if(s[i]-'0' !=0 and (i+1)< s.size() and (s[i] - '0')*10 + (s[i+1] - '0') <= 26) ans += f(s, i+2);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        dp.clear();
        dp.resize(105, -1);
        return f(s,0);
    }
};