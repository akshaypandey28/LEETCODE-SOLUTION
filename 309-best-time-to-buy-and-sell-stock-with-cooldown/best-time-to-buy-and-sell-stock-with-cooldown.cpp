class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int buy,vector<int> &prices){
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        int ans=INT_MIN;
        ans=f(i+1,buy,prices); //avoid case no sell and no buy both included that's why but has no effect
        if(buy==0) ans=max(-prices[i]+f(i+1,1,prices),ans ); //on ith day buy
        else      ans=max(prices[i]+f(i+2,0,prices) , ans) ; //on ith day sell
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.clear();
        dp.resize(n, vector<int>(2, -1));
        return f(0,0,prices);
    }
};