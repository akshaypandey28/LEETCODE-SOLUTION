class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int sum=0;
        int mini=INT_MAX;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                mini=min(mini,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return (mini==INT_MAX)? 0 : mini;
    }
};