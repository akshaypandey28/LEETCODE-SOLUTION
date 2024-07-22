class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Sliding window
        // Maintain a window which keeps only k zeros
        // If zeros > k then pop till zeros becomes equal to k
        queue<int> q;
        int ans = 0;
        int zero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                q.push(1);
                ans = max(ans, static_cast<int>(q.size()));
            }
            else {
                q.push(0);
                zero++;
                if (zero <= k) ans = max(ans, static_cast<int>(q.size()));
                if (zero > k) {
                    while (zero != k) {
                        if (q.front() == 0) zero--;
                        q.pop();
                    }
                }
            }
        }
        ans = max(ans, static_cast<int>(q.size()));
        return ans;
    }
};
