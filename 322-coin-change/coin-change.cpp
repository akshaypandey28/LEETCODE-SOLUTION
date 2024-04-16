class Solution {
public:
    vector<int> dp;
    int f(vector<int>& coins,int amount){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int ans=INT_MAX;

        for(int j=0; j<coins.size(); j++){
            if(amount-coins[j] < 0) continue;
            ans=min(ans,f(coins,amount-coins[j]));
        }
        if(ans==INT_MAX) return dp[amount]=INT_MAX;
        return dp[amount]=1+ans;

    }
    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        dp.resize(100005,-1);
        int ans=f(coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};