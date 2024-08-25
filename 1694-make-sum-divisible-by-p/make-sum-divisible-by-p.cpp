class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        int target = sum % p;
        if (target == 0) return 0;

        unordered_map<int, int> m;
        m[0] = -1;
        int prefix = 0;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p; // i want to find the subarray whose sum can become equal to target
            int key = (prefix - target + p) % p; // Handling Negative Remainders
            if (m.find(key) != m.end()) ans = min(ans, i - m[key]); // Check for the subarray
            m[prefix] = i;
        }
        return (ans == nums.size() ? -1 : ans);
    }
};
