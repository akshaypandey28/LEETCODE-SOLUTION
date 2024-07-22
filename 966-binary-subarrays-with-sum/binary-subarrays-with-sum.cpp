class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // zero sum always exist

        for (int num : nums) {
            sum += num;
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                ans += prefixSumCount[sum - goal];
            }
            prefixSumCount[sum]++;
        }
        
        return ans;
    }
};
