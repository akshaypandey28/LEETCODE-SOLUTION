class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>> ans;
        for(int i=0; i<n; i++){
            int count=0;
            vector<int> temp;
            for(int j=i; j<n; j++){
                if(nums[j]%p==0) count++;
                if(count>k) break;
                temp.push_back(nums[j]);
                ans.insert(temp);
            }
        }
        return ans.size();
    }
};