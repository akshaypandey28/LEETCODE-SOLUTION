class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //actually i have to pick minimum buy price and maximum buy price on traversing the array
        int profit=0;
        int buy=prices[0];
        for(int i=1; i<prices.size(); i++){
            int sell=prices[i]-buy;

            if(sell<0) buy=prices[i];
            
            else profit=max(profit,sell);
        }
        return profit;
    }
};