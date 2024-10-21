class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j,vector<int> &nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i; k<=j; k++){
            int coins=nums[i - 1] * nums[k] * nums[j + 1];
            int remaining=f(i,k-1,nums)+f(k+1,j,nums);
            ans=max(ans,coins+remaining);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        dp.clear();
        dp.resize(n+2,vector<int>(n+2,-1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return f(1,n,nums);
    }
};