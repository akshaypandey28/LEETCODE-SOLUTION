class Solution {
public:
    vector<int> dp;
    long long solve(vector<int> &cost,int i,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(solve(cost,i+1,n) , solve(cost,i+2,n));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.clear();
        dp.resize(n,-1);
        return min(solve(cost,0,n) , solve(cost,1,n));
    }
};