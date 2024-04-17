//2nd method bottom up solution
class Solution {
public:
    vector<vector<int> > dp;
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0; i<nums.size(); i++) s+=nums[i];
        if(s%2!=0) return false;
        dp.clear();
        dp.resize(205, vector<int> (20005, false));
        int k = s/2; //k is half of the total sum
        for(int i = 0; i < n; i++) dp[i][0] = true; // base case
        for(int i = n-1; i >= 0; i--) {
            for(int j = 1; j <= k; j++) {
                if(nums[i] <= j)
                    dp[i][j] = dp[i+1][j-nums[i]] or dp[i+1][j];
                else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][k];
    }
};