class Solution {
public:
//exactly same as leetcode 930
//i can treat all even as 0 and all odd as 1 because i don't have to care about even and only for odd so put all odd
//as 1
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2) nums[i]=1;
            else nums[i]=0;
        }
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // zero sum always exist

        for (int num : nums) {
            sum += num;
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                ans += prefixSumCount[sum - k];
            }
            prefixSumCount[sum]++;
        }
        
        return ans;
    }
};