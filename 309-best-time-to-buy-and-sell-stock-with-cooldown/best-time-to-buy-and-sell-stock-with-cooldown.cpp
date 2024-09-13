class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> d(n+2,vector<int>(2,0)); //n+2 because of i+2 in else condition if n=5 , i=4 , i+2=6 that's why
        //d contains at least 6th row
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