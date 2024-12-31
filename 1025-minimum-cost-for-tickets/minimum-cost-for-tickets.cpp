class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,0);
        for(int i=n-1; i>=0; i--){
            //1 day
            int cost_1=costs[0]+dp[i+1];

            //7 day
            int j=i; 
            while(j<n and days[j] < days[i]+7) j++;
            int cost_7=costs[1]+dp[j];

            //30 day
            j=i;
            while(j<n and days[j] < days[i]+30) j++;
            int cost_30=costs[2]+dp[j];

            dp[i]=min({cost_1,cost_7,cost_30});
        }
        return dp[0];
    }
};