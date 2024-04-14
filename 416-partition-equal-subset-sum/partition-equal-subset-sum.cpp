class Solution {
public:
    vector<int> dp;

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalSum % 2 != 0) return false; // If total sum is odd, can't partition into two equal subsets
        
        int targetSum = totalSum / 2;
        
        dp.resize(targetSum + 1, false);
        dp[0] = true; // Base case: subset with sum 0 is always possible
        
        for (int num : nums) {
            for (int j = targetSum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[targetSum];
    }
};
