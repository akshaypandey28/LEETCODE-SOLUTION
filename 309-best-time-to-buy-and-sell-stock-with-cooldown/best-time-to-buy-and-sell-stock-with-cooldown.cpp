class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int buy,vector<int> &prices){
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        int profit=INT_MIN;
        if(buy==0){
            profit=max(-prices[i]+f(i+1,1,prices) , 0 + f(i+1,0,prices)); //on ith day buy or not buy
        }
        else{
            profit=max(prices[i]+f(i+2,0,prices) , 0 + f(i+1,1,prices)) ; //on ith day sell or not sell
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.clear();
        dp.resize(n, vector<int>(2, -1));
        return f(0,0,prices);
    }
};