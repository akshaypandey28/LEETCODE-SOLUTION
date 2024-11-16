class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        //buy on the ith day and sell is on the (i+1)th day
        for(int i=1; i<prices.size(); i++){
            int buy=prices[i]-prices[i-1];
            if(buy>0) ans+=buy;
        }
        return ans;
    }
};