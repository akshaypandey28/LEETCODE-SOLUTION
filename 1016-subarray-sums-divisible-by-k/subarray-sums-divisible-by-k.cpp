class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;  // Initialize with 1 to count subarrays that directly sum to a multiple of k
        int count = 0;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remainder = sum % k;
            if (remainder < 0) remainder += k;  // Ensure remainder is positive
            
            if (m.find(remainder) != m.end()) {
                count += m[remainder];
            }
            
            m[remainder]++;
        }
        
        return count;
    }
};
