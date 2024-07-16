class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=0;
        int ans=0;
        int maxi=INT_MIN;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]>maxi){
                maxi=nums[j];
                count=1;
                ans=1; //because we found a new element which is greater than maxi that's why ans is set to 1
            }
            else if(nums[j]==maxi) count++;
            else count=0;

            ans=max(ans,count);
        }
        
        return ans;
    }
};