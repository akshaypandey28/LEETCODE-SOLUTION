class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),dp1(n,1);
        for(int i=0; i<n; i++){ //LIS from forward 
            for(int j=0; j<=i-1;j++){
                if(nums[j]<nums[i] and dp[i]<1+dp[j]) dp[i]=1+dp[j];
            }
        }

        for(int i=n-1; i>=0; i--){ //LIS from backward
            for(int j=n-1; j>i; j--){
                if(nums[j]<nums[i] and dp1[i]<1+dp1[j]) dp1[i]=1+dp1[j];
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(dp[i]!=1 and dp1[i]!=1) ans=max(ans,dp[i]+dp1[i]-1); //-1 such that nums[i] can't be included two times
        }
        return n-ans;
    }
};