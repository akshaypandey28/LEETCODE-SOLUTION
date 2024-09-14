class Solution {
public:
    vector<vector<int>> dp;  
    int txn;
    int f(int i,int buy,vector<int> &prices,int n){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int ans=INT_MIN;
        ans=f(i+1,buy,prices,n); //avoid case;
        if(buy==0) ans=max(-prices[i]+f(i+1,1,prices,n),ans ); //on ith day buy
        else      ans=max(prices[i]-txn+f(i+1,0,prices,n) , ans) ; //on ith day sell
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        txn=fee;
        dp.clear();
        dp.resize(n,vector<int>(2,-1));
        return f(0,0,prices,n);
    }
};