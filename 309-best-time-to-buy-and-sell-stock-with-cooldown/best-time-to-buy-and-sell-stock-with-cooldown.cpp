class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> d(n+2,vector<int>(2,0));
        for(int i=n-1; i>=0; i--){
            for(int buy=1; buy>=0; buy--){
                int ans=INT_MIN;
                ans=d[i+1][buy]; //avoid case no sell and no buy both included that's why but has no effect
                if(buy==0) ans=max(-prices[i]+d[i+1][1],ans ); //on ith day buy
                else      ans=max(prices[i]+d[i+2][0] , ans) ; //on ith day sell
                d[i][buy]=ans;
            }
        }
        return d[0][0];
    }
};