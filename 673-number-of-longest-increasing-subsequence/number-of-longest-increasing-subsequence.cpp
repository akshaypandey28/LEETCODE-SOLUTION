class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i-1;j++){
                if(nums[j]<nums[i] and dp[i]<1+dp[j]) {
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }
                else if(nums[j]<nums[i] and dp[i]==1+dp[j]) count[i]+=count[j];
            }
            ans=max(ans,dp[i]);
        }
        int result=0;
        for(int i=0; i<n; i++){
            if(dp[i]==ans) result+=count[i];
        }
        return result;
    }
};