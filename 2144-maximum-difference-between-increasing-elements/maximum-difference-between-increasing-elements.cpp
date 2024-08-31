class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int diff=nums[0];
        for(int i=1; i<nums.size(); i++){
            ans=max(ans,nums[i]-diff);
            diff=min(diff,nums[i]);
        }
        return (ans==0) ? -1 : ans;
    }
};