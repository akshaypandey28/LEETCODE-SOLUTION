class Solution {
public:
    int MAX = 100001;
    int mod = 1000000007;

    int sumOfGoodSubsequences(vector<int>& nums) {
        vector<int> dp(MAX, 0); // dp for counting subsequences ending at any value
        vector<int> sum(MAX, 0); // dp for computing the sum of subsequences ending at any value

        for (int num : nums) {
            dp[num] = (dp[num] + 1) % mod;
            sum[num] = (sum[num] + num) % mod;

            if (num - 1 >= 0) {
                dp[num] = (dp[num] + dp[num - 1]) % mod;
                sum[num] = (sum[num] + sum[num - 1] + (long long)(dp[num - 1]) * num % mod) % mod;
                // 1st =>khud ki wjh se sum, 2nd => sum of subsequences of num-1 and 3rd => no of
                // subsequences of num-1 and multiply with num then it compute the sum of
                // subsequences of value num
            }

            if (num + 1 < MAX ) {
                dp[num] = (dp[num] + dp[num + 1]) % mod;
                sum[num] = (sum[num] + sum[num + 1] + (long long)(dp[num + 1]) * num % mod) % mod;
                // 1st =>khud ki wjh se sum, 2nd => sum of subsequences of num+1 and 3rd => no of
                // subsequences of num+1 and multiply with num then it compute the sum of
                // subsequences of value num
            }
        }

        long long ans = 0;
        for (int i = 0; i < MAX; i++) ans = (ans + sum[i]) % mod;

        return (int)ans;
    }
};
