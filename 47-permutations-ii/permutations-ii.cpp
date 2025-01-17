class Solution {
public:
    void per(vector<vector<int>> &ans, int i, vector<int> &nums) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> seen; // To track duplicates at the current level
        for (int j = i; j < nums.size(); j++) {
            // Skip duplicates
            if (seen.count(nums[j])) continue;

            seen.insert(nums[j]);

            swap(nums[i], nums[j]);

            per(ans, i + 1, nums);

            swap(nums[i], nums[j]); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        per(ans, 0, nums);
        return ans;
    }
};
