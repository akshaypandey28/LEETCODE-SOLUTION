class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        int buy_ith_day=0; //for buying at minimum cost
        for(int i=1; i<prices.size(); i++){
            buy_ith_day=prices[i]-mini;
            profit=max(profit,buy_ith_day);
            mini=min(prices[i],mini);
        }
        return profit;
    }
};