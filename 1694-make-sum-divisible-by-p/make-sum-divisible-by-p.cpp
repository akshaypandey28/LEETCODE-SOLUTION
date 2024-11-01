class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        //formula => target=curr-prev here curr is sum from to 0 to i that is prefix sum
        //and prev is sum from 0 to j and j<=i
        // prev=curr-target , so i have to look for prev sum which is stored in map using index store
        //and answer is min(ans,i-index of prev) => (ans,i-m[prev])
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        int target = sum % p;
        if (target == 0) return 0;

        unordered_map<int, int> m; //<prev_sum,index>
        m[0] = -1;
        int curr = 0;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            curr = (curr + nums[i]) % p; // i want to find the subarray whose sum can become equal to target
            int prev = (curr - target + p) % p; // Handling Negative Remainders
            if (m.find(prev) != m.end()) ans = min(ans, i - m[prev]); // Check for the subarray
            m[curr] = i;
        }
        return (ans == nums.size() ? -1 : ans);
    }
};
